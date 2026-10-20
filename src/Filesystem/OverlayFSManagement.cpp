// Original locations for overloaded or compiler-generated definitions in this unit:
// Original: arm9/main @ 0x020CD1F0; symbol: _Z21LoadCompressedOverlayRK15OverlayMetadataP7NitroVM; size: 0x8C. (LoadCompressedOverlay(OverlayMetadata const&, NitroVM*))
// Original: arm9/main @ 0x020CD27C; symbol: _Z21LoadCompressedOverlayRK15OverlayMetadata; size: 0x90. (LoadCompressedOverlay(OverlayMetadata const&))
#include "Filesystem/OverlayFSManagement.h"
#include "Filesystem/FSInnerDefs.h"
#include "System/Cache.h"
#include "System/Memory.h"
#include "System/BiosData.h"
#include <globaldefs.h>
#include <asmhacks.h>

#pragma optimize_for_size off

#if defined(jpn)
#define DecompressAndStaticInitializeOverlay_UnknownRoleInitializedBytes data_020f2e58
#define VerifyDownloadPlayStruct_UnknownRoleDataReferences data_020f23fc

#define MIi_UncompressBackward MIi_UncompressBackward
#define DisableInterruptsAndHaltForever func_020cb6ac
#define System_ExecuteSHA1HashOperation func_020c2708
#endif

// might be some kind of overlay-like thing for download play
extern struct UnknownDownloadPlayStruct
{
    unsigned int unknown[5];
} DecompressAndStaticInitializeOverlay_UnknownRoleInitializedBytes[];

#if defined(usa)
#define ADDR_FIRST_DOWNLOAD_PLAY_STRUCT 0x020f2e44
#elif defined(jpn)
#define ADDR_FIRST_DOWNLOAD_PLAY_STRUCT 0x020f2e58
#endif

extern struct {
    const void* pointer;
    unsigned int length;
} VerifyDownloadPlayStruct_UnknownRoleDataReferences;

extern "C"
{
    int MIi_UncompressBackward(unsigned int);
    void DisableInterruptsAndHaltForever();
    void System_ExecuteSHA1HashOperation(UnknownDownloadPlayStruct*, unsigned, unsigned, unsigned char*, unsigned);
}


// Original: arm9/main @ 0x020CCF7C; symbol: _Z25GetOverlaySizeOnCartridgeRK15OverlayMetadata; size: 0x1C.
unsigned int GetOverlaySizeOnCartridge(const OverlayMetadata& overlay)
{
    bool isCompressed = overlay.overlayFlags & (1 << OVERLAY_FLAG_COMPRESSED);
    if (!isCompressed)
        return overlay.uncompressedSize;
    return overlay.compressedSize;
}

// Original: arm9/main @ 0x020CCF98; symbol: _Z29InvalidateCacheAndZeroOverlayRK15OverlayMetadata; size: 0x3C.
void InvalidateCacheAndZeroOverlay(const OverlayMetadata &overlay)
{
    unsigned char* startAddr = (unsigned char*)overlay.loadAddress;
    unsigned int copySize = overlay.uncompressedSize;
    unsigned int totalSize = copySize + overlay.bssSectionSize;

    InvalidateInstructionCacheRange(startAddr, totalSize);
    InvalidateDataCacheRange(startAddr, totalSize);
    VectorizedMemset(startAddr + copySize, 0, totalSize - copySize);
}

// Original: arm9/main @ 0x020CCFD4; symbol: _Z28CreateFileAccessorForOverlayP17NitroFileAccessorRK15OverlayMetadata; size: 0x28.
void CreateFileAccessorForOverlay(NitroFileAccessor *outAccessor, const OverlayMetadata &overlay)
{
    NitroFileAccessor temp;
    temp.handle = &ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2;
    temp.fileID = overlay.nitroFileID;
    
    // this cast forces the temporary struct to be created on the stack
    // (writing *&temp, or *(&temp), isn't enough)
    *outAccessor = *(NitroFileAccessor*)&temp;
}

// Original: arm9/main @ 0x020CCFFC; symbol: _Z28LoadOverlayMetadataFromNitroP15OverlayMetadatabjP11NitroHandlejjjj; size: 0xF8.
bool LoadOverlayMetadataFromNitro(OverlayMetadata *into, bool isArm7,
                unsigned int overlayIdx, NitroHandle *romHandle,
                unsigned int arm9OverlayTableStart, unsigned int arm9OverlayTableSize,
                unsigned int arm7OverlayTableStart, unsigned int arm7OverlayTableSize)
{
    unsigned int offset;
    unsigned int start;
    unsigned int size;
    
    if (!isArm7)
    {
        start = arm9OverlayTableStart;
        size = arm9OverlayTableSize;
    }
    else
    {
        start = arm7OverlayTableStart;
        size = arm7OverlayTableSize;
    }

    if (size <= (offset = overlayIdx * 0x20))
        return false;

    NitroVM machine;
    NitroVM_Initialize(&machine);
    // The compiler loves combining shifts into additions, so elides offset by
    // just using start + (overlayIdx << 5). But the target assembly performs
    // the shift early, so some inline assembly can forcefully cancel this optimization
    {
    NitroVM* arg_machine;
    NitroHandle* arg_handle;
    unsigned int arg_readStart;
    unsigned int arg_readEnd;
    unsigned int arg_capacity;

    __asm("mvn arg_capacity, 0");
    arg_machine = &machine;
    __asm("mov arg_handle, romHandle");
    __asm("add arg_readStart, start, offset");
    arg_readEnd = start + size;
    DECLARE_ASM_NOP();

    // equiv to NitroVM_PrepareRead(&machine, romHandle, start + (overlayIdx << 5), start + size, -1)
    if (!NitroVM_PrepareRead(arg_machine, arg_handle, arg_readStart, arg_readEnd, arg_capacity))
        return false;
    }

    if (NitroVM_ReadSync(&machine, into, 0x20) != 0x20)
    {
        NitroVM_FinishRead(&machine);
        return false;
    }

    NitroVM_FinishRead(&machine);
    into->isArm7 = isArm7;

    NitroFileAccessor overlayAccessor;
    CreateFileAccessorForOverlay(&overlayAccessor, *into);
    if (!NitroVM_PrepareReadFileByID(&machine, overlayAccessor))
        return false;
    
    into->romStorageOffset = machine.fileInfo.startOffset;
    into->romStorageSize = machine.fileInfo.endOffset - machine.fileInfo.startOffset;
    NitroVM_FinishRead(&machine);
    return true;
}

// Original: arm9/main @ 0x020CD0F4; symbol: _Z19LoadOverlayMetadataP15OverlayMetadatabj; size: 0xFC.
bool LoadOverlayMetadata(OverlayMetadata* into, bool isArm7, unsigned int idx)
{
    Struct_0211173c::ArmOverlayDataTableData* armData;
    armData = (!isArm7) ? &ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm9Data : &ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage.arm7Data;

    unsigned int offset;
    const char* source = (const char*)armData->start;
    if (source != NULL)
    {
        if (armData->size <= (offset = idx * 0x20))
            return false;
        const char* shifted;
        OverlayMetadata* copyDst;
        __asm("mov copyDst, into");
        __asm("add shifted, source, offset");
        DECLARE_ASM_NOP();
        MI_CpuCopy8(shifted, copyDst, 0x20);
        into->isArm7 = isArm7;

        NitroVM machine;
        NitroVM_Initialize(&machine);
        NitroFileAccessor accessor;
        CreateFileAccessorForOverlay(&accessor, *into);
        if (!NitroVM_PrepareReadFileByID(&machine, accessor))
            return false;

        into->romStorageOffset = machine.fileInfo.startOffset;
        into->romStorageSize = machine.fileInfo.endOffset - machine.fileInfo.startOffset;
        NitroVM_FinishRead(&machine);
        return true;
    }
    else
    {
        CartridgeHeader::OverlayTableValues* overlay = 
            (CartridgeHeader::OverlayTableValues*)BIOS_ADDR_OVERLAY_TABLE_VALUES;
        return LoadOverlayMetadataFromNitro(into, isArm7, idx, &ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2,
            overlay->arm9TableStart, overlay->arm9TableSize,
            overlay->arm7TableStart, overlay->arm7TableSize);
    }
}

bool LoadCompressedOverlay(const OverlayMetadata &overlay, NitroVM *machine)
{
    NitroVM_Initialize(machine);
    NitroFileAccessor accessor;
    CreateFileAccessorForOverlay(&accessor, overlay);
    if (!NitroVM_PrepareReadFileByID(machine, accessor))
        return false;
    
    unsigned int cartridgeSize = GetOverlaySizeOnCartridge(overlay);
    InvalidateCacheAndZeroOverlay(overlay);
    if (NitroVM_ReadAsync(machine, (void*)overlay.loadAddress, cartridgeSize) != cartridgeSize)
    {
        NitroVM_FinishRead(machine);
        return false;
    }

    return true;
}

bool LoadCompressedOverlay(const OverlayMetadata& overlay)
{
    NitroVM machine;
    NitroVM_Initialize(&machine);
    NitroFileAccessor accessor;
    CreateFileAccessorForOverlay(&accessor, overlay);
    if (!NitroVM_PrepareReadFileByID(&machine, accessor))
        return false;
    
    unsigned int cartridgeSize = GetOverlaySizeOnCartridge(overlay);
    InvalidateCacheAndZeroOverlay(overlay);
    if (NitroVM_ReadSync(&machine, (void*)overlay.loadAddress, cartridgeSize) != cartridgeSize)
    {
        NitroVM_FinishRead(&machine);
        return false;
    }

    NitroVM_FinishRead(&machine);
    return true;
}

// Original: arm9/main @ 0x020CD30C; symbol: _Z24VerifyDownloadPlayStructRK25UnknownDownloadPlayStructjj; size: 0x94.
bool VerifyDownloadPlayStruct(const UnknownDownloadPlayStruct& data,
    unsigned int loadAddress, unsigned int size)
{
    UnknownDownloadPlayStruct clone;
    VectorizedMemset(&clone, 0, sizeof(UnknownDownloadPlayStruct));

    unsigned char buffer[64];
    MI_CpuCopy8(VerifyDownloadPlayStruct_UnknownRoleDataReferences.pointer, buffer, VerifyDownloadPlayStruct_UnknownRoleDataReferences.length);
    System_ExecuteSHA1HashOperation(&clone, loadAddress, size, buffer, VerifyDownloadPlayStruct_UnknownRoleDataReferences.length);

    unsigned int offsetCounter = 0;
    unsigned int* cloneReader = &clone.unknown[0];
    do {
        if (*cloneReader != *(unsigned int*)((int)&data + offsetCounter))
            break;
        offsetCounter += 4;
        cloneReader++;
    } while (offsetCounter < sizeof(UnknownDownloadPlayStruct));

    return offsetCounter == sizeof(UnknownDownloadPlayStruct);
}

void DecompressAndStaticInitializeOverlay(const OverlayMetadata& overlay)
{
    unsigned int initialSize = GetOverlaySizeOnCartridge(overlay);

    // extremely weird code that never runs (only for DS Download Play?)
    if (IsDownloadPlay())
    {
        bool result = false;
        if (overlay.overlayFlags & (1 << OVERLAY_FLAG_DOWNLOAD_PLAY))
        {
            // Using two different formats for the same address (number and label)
            // forces the word to appear twice
            UnknownDownloadPlayStruct* start = (UnknownDownloadPlayStruct*)ADDR_FIRST_DOWNLOAD_PLAY_STRUCT;
            UnknownDownloadPlayStruct* end = DecompressAndStaticInitializeOverlay_UnknownRoleInitializedBytes;
            if (overlay.overlayIndex < end - start)
            {
                result = VerifyDownloadPlayStruct(
                    *(UnknownDownloadPlayStruct*)((int)start + sizeof(UnknownDownloadPlayStruct) * overlay.overlayIndex),
                    overlay.loadAddress, initialSize);
            }
        }
        if (!result)
        {
            VectorizedMemset((void*)overlay.loadAddress, 0, initialSize);
            DisableInterruptsAndHaltForever();
            return;
        }
    }

    // Decompress the overlay in place
    if (overlay.overlayFlags & (1 << OVERLAY_FLAG_COMPRESSED))
        MIi_UncompressBackward(overlay.loadAddress + initialSize);
    
    CleanInvalidateCacheRange((void*)overlay.loadAddress, overlay.uncompressedSize);
    OverlayMetadata::StaticInitializer* pInitializer = overlay.staticInitStart;
    OverlayMetadata::StaticInitializer* initializerEnd = overlay.staticInitEnd;
    if (pInitializer < initializerEnd)
    {
        do {
            if (*pInitializer)
                (*pInitializer)();
            pInitializer++;
        } while (pInitializer < initializerEnd);
    }
}