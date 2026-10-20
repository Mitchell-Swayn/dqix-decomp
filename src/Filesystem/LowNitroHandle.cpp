#include "Filesystem/FSInnerDefs.h"
#include "System/Memory.h"
#include "System/Interrupts.h"
#include <globaldefs.h>

#pragma optimize_for_size off

int DefaultNitroReadProc(NitroHandle* handle, void* dst, unsigned int offset, unsigned int len);
int DefaultNitroWriteProc(NitroHandle* handle, const void* src, unsigned int offset, unsigned int len);
int MemoryMappedMetadataReadProc(NitroHandle* handle, void* dst, unsigned int offset, unsigned int len);

// Original: arm9/main @ 0x020CC0FC; symbol: _Z22NitroHandle_InitializeP11NitroHandle; size: 0x2C.
void NitroHandle_Initialize(NitroHandle* handle)
{
    VectorizedMemset(handle, 0, sizeof(NitroHandle));
    handle->taskWaitBlock.last = NULL;
    handle->taskWaitBlock.first = NULL;
    handle->busReleaseBlock.last = NULL;
    handle->busReleaseBlock.first = NULL;
}

// Original: arm9/main @ 0x020CC128; symbol: _Z27NitroHandle_FindBySignaturePKci; size: 0x40.
NitroHandle* NitroHandle_FindBySignature(const char* str, int len)
{
    unsigned int targetSig = Nitro_CalculateSignature(str, len);
    int oldState = DisableIRQInterrupts();

    NitroHandle* handle = NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.firstHandle;

    while (handle != NULL && handle->signature != targetSig)
    {
        handle = handle->pNextHandle;
    }

    SetIRQInterruptState(oldState);
    return handle;
}

// Original: arm9/main @ 0x020CC168; symbol: _Z27NitroHandle_AddToHandleListP11NitroHandlePKci; size: 0xB4.
CBool NitroHandle_AddToHandleList(NitroHandle* handle, const char* str, int len)
{
    CBool result = false;
    int oldState = DisableIRQInterrupts();
    if (NitroHandle_FindBySignature(str, len) == NULL)
    {
        if (NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.firstHandle == NULL)
        {
            NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.firstHandle = handle;
            NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot.handle = handle;
            NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot.handleSubtableOffset = 0;
            NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot.firstFileID = 0;
            NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot.dirID = 0;
        }
        else
        {
            // At the end of this, currentEntry holds the last entry in the list
            // and nextEntry is null (points past the end)
            NitroHandle* currentEntry = NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.firstHandle;
            NitroHandle* nextEntry = currentEntry->pNextHandle;
            if (nextEntry != NULL)
            {
                do
                {
                    currentEntry = nextEntry;
                    nextEntry = nextEntry->pNextHandle;
                } while (nextEntry != NULL);
            }

            currentEntry->pNextHandle = handle;
            handle->pPrevHandle = currentEntry;
        }
        handle->signature = Nitro_CalculateSignature(str, len);
        result = true;
        handle->flags |= (1 << NITROHANDLE_FLAG_IS_IN_MAIN_LIST);
    }

    SetIRQInterruptState(oldState);
    return result;
}

// Original: arm9/main @ 0x020CC21C; symbol: _Z32NitroHandle_RemoveFromHandleListP11NitroHandle; size: 0x84.
void NitroHandle_RemoveFromHandleList(NitroHandle* handle)
{
    if (handle->signature == 0)
        return;

    int oldState = DisableIRQInterrupts();

    if (handle->pNextHandle != NULL)
        handle->pNextHandle->pPrevHandle = handle->pPrevHandle;

    if (handle->pPrevHandle != NULL)
        handle->pPrevHandle->pNextHandle = handle->pNextHandle;

    handle->signature = 0;
    handle->pPrevHandle = NULL;
    handle->pNextHandle = NULL;
    handle->flags &= ~(1 << NITROHANDLE_FLAG_IS_IN_MAIN_LIST);

    if (NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot.handle == handle)
    {
        NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot.handle = NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.firstHandle;
        NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot.handleSubtableOffset = 0;
        NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot.firstFileID = 0;
        NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage.romFSRoot.dirID = 0;
    }

    SetIRQInterruptState(oldState);
}

// Original: arm9/main @ 0x020CC2A0; symbol: _Z20NitroHandle_PopulateP11NitroHandlePvjjjjPFiS0_S1_jjEPFiS0_PKvjjE; size: 0x70.
CBool NitroHandle_Populate(NitroHandle* handle, void* image,
        unsigned int fatOffset, unsigned int fatSize,
        unsigned int fntOffset, unsigned int fntSize,
        NitroHandle::ReadProc loadProc, NitroHandle::WriteProc saveProc)
{
    handle->pFileImage = image;
    handle->fatSize = fatSize;
    handle->fatOffsetFast = handle->fatOffset = fatOffset;
    handle->nameTableSize = fntSize;
    handle->nameTableOffsetFast = handle->nameTableOffset = fntOffset;

    handle->readProc = (loadProc == NULL) ? &DefaultNitroReadProc : loadProc;
    handle->writeProc = (saveProc == NULL) ? &DefaultNitroWriteProc : saveProc;

    handle->fastReadProc = handle->readProc;
    handle->tableRawPointer = NULL;
    handle->flags |= (1 << NITROHANDLE_FLAG_IS_POPULATED);
    return true;
}

// Original: arm9/main @ 0x020CC310; symbol: _Z19NitroHandle_DestroyP11NitroHandle; size: 0xC0.
CBool NitroHandle_Destroy(NitroHandle* handle)
{
    int oldState = DisableIRQInterrupts();
    
    if (GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_IS_POPULATED) != 0)
    {
        // Silly unused volatile read of the flags. Assembly is extra misleading,
        // can make it look like it's the 2nd argument, but this is wrong
        CBool paused = (handle->flags, NitroHandle_Pause(handle));
        handle->flags |= (1 << NITROHANDLE_FLAG_DESTRUCTION_UNDERWAY);
        
        NitroVM* machine = handle->linkToFirstVM.pNext;
        if (machine != NULL)
        {
            do {
                NitroVM* next = machine->links.pNext;
                NitroVM_UnlinkAndStoreResult(machine, NITRO_RESULT_INVALID_HANDLE);
                machine = next;
            } while (machine != NULL);
        }
        handle->linkToFirstVM.pNext = NULL;
        if (paused)
            NitroHandle_Unpause(handle);

        handle->pFileImage = NULL;
        handle->fatOffsetFast = 0;
        handle->fatSize = 0;
        handle->nameTableOffsetFast = 0;
        handle->nameTableSize = 0;
        handle->nameTableOffset = 0;
        handle->fatOffset = 0;

        handle->flags &= ~((1 << NITROHANDLE_FLAG_DESTRUCTION_UNDERWAY) | (1 << NITROHANDLE_FLAG_VM_LIST_DIRTY) | (1 << NITROHANDLE_FLAG_IS_POPULATED));
    }
    SetIRQInterruptState(oldState);
    return true;
}

// Original: arm9/main @ 0x020CC3D0; symbol: _Z26NitroHandle_LoadFileTablesP11NitroHandlePvj; size: 0x124.
unsigned int NitroHandle_LoadFileTables(NitroHandle* handle, void* into, unsigned int capacity)
{
    unsigned int neededSpace = (handle->fatSize + handle->nameTableSize + 0x3f) & ~0x1f;

    if (neededSpace <= capacity)
    {
        void* alignedPtr = (void*)(((unsigned int)into + 0x1f) & ~0x1f);
        NitroVM vm;
        NitroVM_Initialize(&vm);
        if (NitroVM_PrepareRead(&vm, handle, 
            handle->fatOffsetFast,
            handle->fatOffsetFast + handle->fatSize, -1))
        {
            if (NitroVM_ReadSync(&vm, alignedPtr, handle->fatSize) < 0)
                VectorizedMemset(alignedPtr, 0, handle->fatSize);
            NitroVM_FinishRead(&vm);
        }
        handle->fatOffsetFast = (unsigned int)alignedPtr;
        alignedPtr = (void*)((unsigned int)alignedPtr + handle->fatSize);

        if (NitroVM_PrepareRead(&vm, handle, 
            handle->nameTableOffsetFast,
            handle->nameTableOffsetFast + handle->nameTableSize, -1))
        {
            if (NitroVM_ReadSync(&vm, alignedPtr, handle->nameTableSize) < 0)
                VectorizedMemset(alignedPtr, 0, handle->nameTableSize);
            NitroVM_FinishRead(&vm);
        }

        handle->nameTableOffsetFast = (unsigned int)alignedPtr;
        handle->tableRawPointer = into;
        handle->fastReadProc = &MemoryMappedMetadataReadProc;
        handle->flags |= (1 << NITROHANDLE_FLAG_TABLES_LOADED_IN_MEMORY);
    }

    return neededSpace;
}

// Original: arm9/main @ 0x020CC4F4; symbol: _Z29NitroHandle_ReleaseFileTablesP11NitroHandle; size: 0x8C.
void* NitroHandle_ReleaseFileTables(NitroHandle* handle)
{
    void* oldPtr = NULL;
    if (GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_IS_POPULATED))
    {
        int paused = NitroHandle_Pause(handle);
        if (GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_TABLES_LOADED_IN_MEMORY))
        {
            handle->flags &= ~(1 << NITROHANDLE_FLAG_TABLES_LOADED_IN_MEMORY);
            oldPtr = handle->tableRawPointer;
            handle->tableRawPointer = NULL;
            handle->fatOffsetFast = handle->fatOffset;
            handle->nameTableOffsetFast = handle->nameTableOffset;
            handle->fastReadProc = handle->readProc;
        }
        if (paused)
            NitroHandle_Unpause(handle);
    }
    return oldPtr;
}

// Original: arm9/main @ 0x020CC580; symbol: _Z17NitroHandle_PauseP11NitroHandle; size: 0x9C.
CBool NitroHandle_Pause(NitroHandle* handle)
{
    int oldState = DisableIRQInterrupts();
    CBool changeState = GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_QUEUE_PAUSED) == 0;
    if (changeState)
    {
        int busHeld = GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_NDS_BUS_HELD);
        int oldFlags = handle->flags;
        if (busHeld)
        {
            handle->flags = oldFlags | (1 << NITROHANDLE_FLAG_AWAITING_BUS_RELEASE);
            do {
                BlockCurrentContext(&handle->busReleaseBlock);
            } while (GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_AWAITING_BUS_RELEASE));
        }
        else
        {
            handle->flags = oldFlags | (1 << NITROHANDLE_FLAG_QUEUE_PAUSED);
        }
    }

    SetIRQInterruptState(oldState);
    return changeState;
}

// Original: arm9/main @ 0x020CC61C; symbol: _Z19NitroHandle_UnpauseP11NitroHandle; size: 0x70.
CBool NitroHandle_Unpause(NitroHandle* handle)
{
    NitroVM* machine = NULL;
    int oldState = DisableIRQInterrupts();

    CBool skip = GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_QUEUE_PAUSED) == 0;
    if (!skip)
    {
        handle->flags &= ~(1 << NITROHANDLE_FLAG_QUEUE_PAUSED);
        machine = NitroHandle_AdvanceCommandQueue(handle);
    }

    SetIRQInterruptState(oldState);
    if (machine != NULL)
        NitroVM_ProcessReadyCommandQueueEntries(machine);
    return skip;
}

// Original: arm9/main @ 0x020CC68C; symbol: _Z29NitroHandle_SetOpcodeOverrideP11NitroHandlePFiP7NitroVMiEj; size: 0x20.
void NitroHandle_SetOpcodeOverride(NitroHandle* handle, NitroHandle::CommandOverride fnOverride, unsigned int mask)
{
    if (mask == 0)
        fnOverride = NULL;
    else if (fnOverride == NULL)
        mask = 0;
    
    handle->instructionOverride = fnOverride;
    handle->overrideOpcodeFlags = mask;
}

// Original: arm9/main @ 0x020CC6AC; symbol: _Z28NitroHandle_OnTaskCompletionP11NitroHandlei; size: 0x84.
void NitroHandle_OnTaskCompletion(NitroHandle* handle, int result)
{
    if (GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_ASYNC_COMMAND_IN_PROGRESS))
    {
        int previousFlags = handle->flags;
        NitroVM* firstVM = handle->linkToFirstVM.pNext;
        handle->flags = previousFlags & ~(1 << NITROHANDLE_FLAG_ASYNC_COMMAND_IN_PROGRESS);
        NitroVM_UnlinkAndStoreResult(firstVM, result);
        NitroVM* fs = NitroHandle_AdvanceCommandQueue(handle);
        if (fs != NULL)
            NitroVM_ProcessReadyCommandQueueEntries(fs);
    }
    else
    {
        NitroVM* firstVM = handle->linkToFirstVM.pNext;
        int oldState = DisableIRQInterrupts();
        firstVM->storedResult = result;
        handle->flags &= ~(1 << NITROHANDLE_FLAG_SYNC_COMMAND_IN_PROGRESS);
        UnblockContexts(&handle->taskWaitBlock);
        SetIRQInterruptState(oldState);
    }
}

// Original: arm9/main @ 0x020CC730; symbol: _Z23InitializeROMFilesystemi; size: 0x28.
void InitializeROMFilesystem(int dmaChannel)
{
    if (InitializeROMFilesystem_UnknownRoleZeroInitializedStorage)
        return;
    InitializeROMFilesystem_UnknownRoleZeroInitializedStorage = true;
    InitializeROMFilesystem_Internal(dmaChannel);
}

// Original: arm9/main @ 0x020CC758; symbol: _Z18NitroVM_InitializeP7NitroVM; size: 0x28.
void NitroVM_Initialize(NitroVM* vm)
{
    vm->links.pPrev = NULL;
    vm->links.pNext = NULL;
    vm->blockedContexts.last = NULL;
    vm->blockedContexts.first = NULL;
    vm->linkedHandle = NULL;
    vm->pendingCommand = NITROVM_OPCODE_MAYBE_INVALID;
    vm->flags = 0;
}

// Original: arm9/main @ 0x020CC780; symbol: _Z29NitroVM_SearchFileOrDirectoryP7NitroVMPKcP17NitroFileAccessorP22NitroDirectoryAccessor; size: 0x144.
int NitroVM_SearchFileOrDirectory(NitroVM* vm, const char* inPath,
        NitroFileAccessor* outFileData, NitroDirectoryAccessor* outDirData)
{
    NitroDirectoryAccessor accessor;
    // Cast to unsigned and remove const for convenience
    unsigned char* path = (unsigned char*)inPath;
    if (path[0] == '/' || path[0] == '\\')
    {
        accessor.handle = SetROMFilesystemRoot_UnknownRoleZeroInitializedStorage.handle;
        accessor.dirID = 0;
        accessor.handleSubtableOffset = 0;
        accessor.firstFileID = 0;
        path++;
    }
    else
    {
        accessor = SetROMFilesystemRoot_UnknownRoleZeroInitializedStorage;
        int signatureIdx = 0;
        do
        {
            if (path[signatureIdx] == '\0' || path[signatureIdx] == '/' || path[signatureIdx] == '\\')
                break;
            if (path[signatureIdx] != ':')
                continue;
            
            NitroHandle* handle = NitroHandle_FindBySignature(inPath, signatureIdx);

            if (handle == NULL)
                return false;
            if (!GET_FLAG_BIT(handle->flags, NITROHANDLE_FLAG_IS_POPULATED))
                return false;

            accessor.handle = handle;
            accessor.handleSubtableOffset = 0;
            accessor.firstFileID = 0;
            accessor.dirID = 0;
            path += signatureIdx + 1;
            if (path[0] == '/' || path[0] == '\\')
                path++;
            break;
        } while (++signatureIdx <= 3);
    }

    vm->linkedHandle = accessor.handle;
    vm->args_GetFileOrDirectoryByName.path = path;
    vm->args_GetFileOrDirectoryByName.searchDirectory = accessor;
    if (outDirData != NULL)
    {
        vm->args_GetFileOrDirectoryByName.searchForDirectory = 1;
        vm->args_GetFileOrDirectoryByName.output = outDirData;
    }
    else
    {
        vm->args_GetFileOrDirectoryByName.searchForDirectory = 0;
        vm->args_GetFileOrDirectoryByName.output = outFileData;
    }

    return NitroVM_QueueCommand(vm, NITROVM_OPCODE_GET_FILE_OR_DIRECTORY_BY_NAME);
}

// Original: arm9/main @ 0x020CC8C4; symbol: _Z12NitroVM_ReadP7NitroVMPvii; size: 0x7C.
int NitroVM_Read(NitroVM* vm, void* dst, int capacity, CBool async)
{
    int srcStart = vm->fileInfo.cursorPos;
    int srcEnd = vm->fileInfo.endOffset;
    
    int remainingLength = srcEnd - srcStart;
    
    int lengthToCopy = capacity;
    unsigned int copyOfCapacity = capacity; // unsigned fixes register stuff
    
    if (lengthToCopy > remainingLength)
        lengthToCopy = remainingLength;
    
    if (lengthToCopy < 0)
        lengthToCopy = 0;
    
    vm->args_Read.destination = (char*)dst;
    vm->args_Read.unknown = copyOfCapacity;
    vm->args_Read.length = lengthToCopy;
    
    if (!async)
        vm->flags |= (1 << NITROVM_FLAG_SYNCHRONOUS);
    
    NitroVM_QueueCommand(vm, NITROVM_OPCODE_LOAD);
    
    if (!async)
    {
        if (NitroVM_AwaitCommandCompletion(vm))
            lengthToCopy = vm->fileInfo.cursorPos - srcStart;
        else
            lengthToCopy = -1;
    }

    return lengthToCopy;
}