#include "Filesystem/FSInnerDefs.h"
#include "Filesystem/CardReadManager.h"
#include "System/Interrupts.h"
#include "System/BiosData.h"
#include "System/GamecardBusOwnership.h"
#include <globaldefs.h>

#pragma optimize_for_size off

#if defined(jpn)
#define ProgramData_TextRom data_020f23f8
#endif

extern char ProgramData_TextRom[]; // "rom"

// Original: arm9/main @ 0x020CC940; symbol: _Z18CreateFileAccessorP17NitroFileAccessorPKc; size: 0x40.
CBool CreateFileAccessor(NitroFileAccessor* outAccessor, const char* path)
{
    NitroVM machine;
    NitroVM_Initialize(&machine);

    return NitroVM_SearchFileOrDirectory(&machine, path, outAccessor, NULL) != false;
}

// Original: arm9/main @ 0x020CC980; symbol: _Z19NitroVM_PrepareReadP7NitroVMP11NitroHandlejjj; size: 0x48.
CBool NitroVM_PrepareRead(NitroVM* vm, NitroHandle* handle,
    unsigned int start, unsigned int end, unsigned int fileID)
{
    vm->linkedHandle = handle;
    vm->args_SetFilePointers.fileID = fileID;
    vm->args_SetFilePointers.startOffset = start;
    vm->args_SetFilePointers.endOffset = end;

    // Operand 7 copies capacity into base_a,
    // start into base_b and base_d, end into base_c.
    if (!NitroVM_QueueCommand(vm, NITROVM_OPCODE_SET_FILE_POINTERS))
        return false;

    vm->flags = (vm->flags | (1 << NITROVM_FLAG_READ_POSITIONS_CONFIGURED)) & ~(1 << NITROVM_FLAG_SEARCH_TARGET_IS_DIRECTORY);
    return true;
}

// Accessor passed by value (in registers r1, r2)
// Original: arm9/main @ 0x020CC9C8; symbol: _Z27NitroVM_PrepareReadFileByIDP7NitroVM17NitroFileAccessor; size: 0x70.
bool NitroVM_PrepareReadFileByID(NitroVM* vm, NitroFileAccessor volatile accessor)
{
    NitroHandle* handle = accessor.handle;
    if (handle == NULL)
        return false;

    vm->linkedHandle = handle;
    vm->args_GetFATEntry.accessor.handle = handle;
    vm->args_GetFATEntry.accessor.fileID = accessor.fileID;
    if (!NitroVM_QueueCommand(vm, NITROVM_OPCODE_GET_FAT_ENTRY))
        return false;

    vm->flags = (vm->flags | (1 << NITROVM_FLAG_READ_POSITIONS_CONFIGURED)) & ~(1 << NITROVM_FLAG_SEARCH_TARGET_IS_DIRECTORY);
    return true;
}

// Original: arm9/main @ 0x020CCA38; symbol: _Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc; size: 0x48.
bool NitroVM_PrepareReadFileByPath(NitroVM* vm, const char* path)
{
    NitroFileAccessor accessor;
    if (CreateFileAccessor(&accessor, path))
    {
        if (NitroVM_PrepareReadFileByID(vm, accessor))
            return true;
    }

    return false;
}

// Original: arm9/main @ 0x020CCA80; symbol: _Z18NitroVM_FinishReadP7NitroVM; size: 0x3C.
CBool NitroVM_FinishRead(NitroVM* vm)
{
    // this opcode executes synchronously, so when control returns here all
    // VMs before it will have executed their instructions
    if (!NitroVM_QueueCommand(vm, NITROVM_OPCODE_NOP))
        return false;

    vm->linkedHandle = NULL;
    vm->pendingCommand = NITROVM_OPCODE_MAYBE_INVALID;
    vm->flags &= ~((1 << NITROVM_FLAG_READ_POSITIONS_CONFIGURED) | (1 << NITROVM_FLAG_SEARCH_TARGET_IS_DIRECTORY));
    return true;
}

// Original: arm9/main @ 0x020CCABC; symbol: _Z24NitroVM_WriteOutFilePathP7NitroVMPcj; size: 0x2C.
CBool NitroVM_WriteOutFilePath(NitroVM* vm, char* buffer, unsigned int bufferLength)
{
    if (vm->pendingCommand != NITROVM_OPCODE_GET_FILE_OR_DIRECTORY_PATH)
    {
        vm->args_GetPath.numBytesWritten = 0;
        vm->args_GetPath.directoryID = 0;
    }

    vm->args_GetPath.pathOutput = buffer;
    vm->args_GetPath.outputCapacity = bufferLength;

    return NitroVM_QueueCommand(vm, NITROVM_OPCODE_GET_FILE_OR_DIRECTORY_PATH);
}

// Original: arm9/main @ 0x020CCAE8; symbol: _Z30NitroVM_AwaitCommandCompletionP7NitroVM; size: 0xC0.
CBool NitroVM_AwaitCommandCompletion(NitroVM* vm)
{
    CBool executionPending = false;

    int oldState = DisableIRQInterrupts();

    if (GET_FLAG_BIT(vm->flags, NITROVM_FLAG_IN_HANDLE_QUEUE))
    {
        // Execute iff flag 6 and flag 2 are both clear.
        executionPending = !(vm->flags & ((1 << NITROVM_FLAG_READY_TO_EXECUTE) | (1 << NITROVM_FLAG_SYNCHRONOUS)));

        if (executionPending)
        {
            vm->flags |= (1 << NITROVM_FLAG_SYNCHRONOUS);
            do {
                BlockCurrentContext(&vm->blockedContexts);
            } while (!(vm->flags & (1 << NITROVM_FLAG_READY_TO_EXECUTE))); // why the different format here?
        }
        else
        {
            do {
                BlockCurrentContext(&vm->blockedContexts);
            } while (GET_FLAG_BIT(vm->flags, NITROVM_FLAG_IN_HANDLE_QUEUE));
        }
    }

    SetIRQInterruptState(oldState);

    if (executionPending)
        return NitroVM_ExecuteAndUnlink(vm);
    else
        return vm->storedResult == NITRO_RESULT_SUCCESS;
}

// Original: arm9/main @ 0x020CCBA8; symbol: _Z21NitroVM_CancelCommandP7NitroVM; size: 0x48.
void NitroVM_CancelCommand(NitroVM* vm)
{
    int oldState = DisableIRQInterrupts();

    if (GET_FLAG_BIT(vm->flags, NITROVM_FLAG_IN_HANDLE_QUEUE))
    {
        // mark for removal from the handle's list of attached VMs
        vm->flags |= (1 << NITROVM_FLAG_MARKED_FOR_UNLINK_FROM_HANDLE);
        vm->linkedHandle->flags |= (1 << NITROHANDLE_FLAG_VM_LIST_DIRTY);
    }
    SetIRQInterruptState(oldState);
}

// Original: arm9/main @ 0x020CCBF0; symbol: _Z17NitroVM_ReadAsyncP7NitroVMPvi; size: 0x10.
int NitroVM_ReadAsync(NitroVM* vm, void* dst, int capacity)
{
    return NitroVM_Read(vm, dst, capacity, true);
}

// Original: arm9/main @ 0x020CCC00; symbol: _Z16NitroVM_ReadSyncP7NitroVMPvi; size: 0x10.
int NitroVM_ReadSync(NitroVM* vm, void* dst, int capacity)
{
    return NitroVM_Read(vm, dst, capacity, false);
}

// Original: arm9/main @ 0x020CCC10; symbol: _Z12NitroVM_SeekP7NitroVMii; size: 0x6C.
CBool NitroVM_Seek(NitroVM* vm, int offset, int whence)
{
    switch (whence)
    {
    case 0: // SEEK_SET
        offset += vm->fileInfo.startOffset;
        break;
    case 1: // SEEK_CUR
        offset += vm->fileInfo.cursorPos;
        break;
    case 2: // SEEK_END
        offset += vm->fileInfo.endOffset;
        break;
    default:
        return false;
    }
        
    if (offset < vm->fileInfo.startOffset)
        offset = vm->fileInfo.startOffset;
    if (offset > vm->fileInfo.endOffset)
        offset = vm->fileInfo.endOffset;

    vm->fileInfo.cursorPos = offset;
    return true;
}

// Original: arm9/main @ 0x020CCC7C; symbol: _Z20SetROMFilesystemRootPKc; size: 0x58.
CBool SetROMFilesystemRoot(const char* path)
{
    NitroVM vm;
    NitroVM_Initialize(&vm);
    NitroDirectoryAccessor accessor;
    if (!NitroVM_SearchFileOrDirectory(&vm, path, NULL, &accessor))
        return false;

    NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot = accessor;
    return true;
}

// Original: arm9/main @ 0x020CCCD4; symbol: _Z29OnCartridgeDataLoadCompletionP11NitroHandle; size: 0x24.
void OnCartridgeDataLoadCompletion(NitroHandle* handle)
{
    int result = CardReadManager_ReadGlobalStatus() ? NITRO_RESULT_5 : NITRO_RESULT_SUCCESS;
    NitroHandle_OnTaskCompletion(handle, result);
}

// Original: arm9/main @ 0x020CCCF8; symbol: _Z21ROMFilesystemLoadProcP11NitroHandlePvjj; size: 0x48.
int ROMFilesystemLoadProc(NitroHandle* handle, void* dst, unsigned offset, unsigned len)
{
    LoadDataFromCartridgeToMemory(ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.dmaChannel, offset, dst, len, &OnCartridgeDataLoadCompletion, handle, true);
    return NITRO_RESULT_TASK_STILL_RUNNING;
}

// Original: arm9/main @ 0x020CCD40; symbol: _Z21ROMFilesystemSaveProcP11NitroHandlePKvjj; size: 0x8.
int ROMFilesystemSaveProc(NitroHandle*, const void*, unsigned, unsigned)
{
    return NITRO_RESULT_FAILURE;
}

// Original: arm9/main @ 0x020CCD48; symbol: _Z27ROMFilesystemOpcodeOverrideP7NitroVMi; size: 0x6C.
int ROMFilesystemOpcodeOverride(NitroVM* vm, int opcode)
{
    if (opcode != NITROVM_OPCODE_SAVE)
    {
        switch (opcode)
        {
        case NITROVM_OPCODE_ACQUIRE_NDS_BUS:
            NitroVM_Command_AcquireCardReadResources(ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.busHolderID);
            return NITRO_RESULT_SUCCESS;
        case NITROVM_OPCODE_RELEASE_NDS_BUS:
            NitroVM_Command_ReleaseCardReadResources(ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.busHolderID);
            return NITRO_RESULT_SUCCESS;
        }
    }
    else // opcode = 1 (save), not possible for ROM data
        return NITRO_RESULT_COMMAND_UNSUPPORTED;

    // Override does not implement command
    return NITRO_RESULT_OPCODE_NOT_IMPLEMENTED;
}

// Original: arm9/main @ 0x020CCDB4; symbol: _Z29UnsupportedFilesystemLoadProcP11NitroHandlePvjj; size: 0x8.
int UnsupportedFilesystemLoadProc(NitroHandle*, void*, unsigned, unsigned)
{
    return NITRO_RESULT_FAILURE;
}

// Original: arm9/main @ 0x020CCDBC; symbol: _Z35UnsupportedFilesystemOpcodeOverrideP7NitroVMi; size: 0x8.
int UnsupportedFilesystemOpcodeOverride(NitroVM*, int)
{
    return NITRO_RESULT_COMMAND_UNSUPPORTED;
}

// Original: arm9/main @ 0x020CCDC4; symbol: _Z32InitializeROMFilesystem_Internalj; size: 0x148.
void InitializeROMFilesystem_Internal(unsigned int channel)
{
    ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.dmaChannel = channel;
    ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.busHolderID = GenerateLockOwnerID();
    ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm9Data.start = NULL;
    ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm9Data.size = 0;
    ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm7Data.start = NULL;
    ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm7Data.size = 0;
    InitializeCardReading();

    NitroHandle_Initialize(&ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2);
    NitroHandle_AddToHandleList(&ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2, ProgramData_TextRom, 3);

    const BootIndicator* biosData = (BootIndicator*)BIOS_ADDR_BOOT_INDICATOR;
    const CartridgeHeader& cartridgeHeader = biosData->cartHeader;
    if (IsDownloadPlay()) // is this even a thing for DQ9?
    {
        ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm9Data.start = (void*)-1;
        ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm9Data.size = 0;
        ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm7Data.start = (void*)-1;
        ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm7Data.size = 0;
        NitroHandle_SetOpcodeOverride(&ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2, &UnsupportedFilesystemOpcodeOverride, -1);
        NitroHandle_Populate(&ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2, NULL, 0, 0, 0, 0,
            &UnsupportedFilesystemLoadProc, &ROMFilesystemSaveProc);
        return;
    }

    NitroHandle_SetOpcodeOverride(&ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2, &ROMFilesystemOpcodeOverride,
        (1 << NITROVM_OPCODE_RELEASE_NDS_BUS) | (1 << NITROVM_OPCODE_ACQUIRE_NDS_BUS) | (1 << NITROVM_OPCODE_SAVE));

    if (cartridgeHeader.fileNameTableOffset == -1 ||
        cartridgeHeader.fileNameTableOffset == 0 ||
        cartridgeHeader.fileAllocTableOffset == -1 ||
        cartridgeHeader.fileAllocTableOffset == 0)
        return;
    
    NitroHandle_Populate(&ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2, NULL, 
        cartridgeHeader.fileAllocTableOffset,
        cartridgeHeader.fileAllocTableSize,
        cartridgeHeader.fileNameTableOffset,
        cartridgeHeader.fileNameTableSize,
        &ROMFilesystemLoadProc,
        &ROMFilesystemSaveProc);
}

// Original: arm9/main @ 0x020CCF0C; symbol: _Z23ChangeROMLoadDMAChannelj; size: 0x50.
unsigned int ChangeROMLoadDMAChannel(unsigned int newChannel)
{
    int oldState = DisableIRQInterrupts();
    unsigned int oldChannel = ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.dmaChannel;
    CBool destructionResult = NitroHandle_Pause(&ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2);
    ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.dmaChannel = newChannel;
    if (destructionResult)
        NitroHandle_Unpause(&ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2);
    SetIRQInterruptState(oldState);
    return oldChannel;
}

// Original: arm9/main @ 0x020CCF5C; symbol: _Z27LoadROMFilesystemFileTablesPvj; size: 0x20.
unsigned int LoadROMFilesystemFileTables(void* where, unsigned int capacity)
{
    return NitroHandle_LoadFileTables(&ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2, where, capacity);
}