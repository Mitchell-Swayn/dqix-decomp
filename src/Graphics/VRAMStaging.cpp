#include "Graphics/VRAMStaging.h"
#include <globaldefs.h>

VRAMStagingManager g_stagingManagerInstance;
unsigned char g_vramStagingBuffer[0x5000];

// Original: arm9/main @ 0x020DC07C; symbol: _Z28LockStagedTextureVRAMCopyingv; size: 0x1C.
void LockStagedTextureVRAMCopying()
{
    g_stagingManagerInstance.textureLockMask_ <<= 1;
    g_stagingManagerInstance.textureLockMask_ |= 1;
}

// Original: arm9/main @ 0x020DC098; symbol: _Z30UnlockStagedTextureVRAMCopyingv; size: 0x18.
void UnlockStagedTextureVRAMCopying()
{
    g_stagingManagerInstance.textureLockMask_ >>= 1;
}

// Original: arm9/main @ 0x020DC0B0; symbol: _Z25AllocateVRAMStagingMemoryj; size: 0x18.
void* AllocateVRAMStagingMemory(unsigned int length)
{
    return g_stagingManagerInstance.AllocateInStagingSpace(length);
}

// Original: arm9/main @ 0x020DC0C8; symbol: _Z21FreeVRAMStagingMemoryPKv; size: 0x18.
void FreeVRAMStagingMemory(const void* allocation)
{
    g_stagingManagerInstance.FreeStagingSpaceAllocation(allocation);
}

// Original: arm9/main @ 0x020DC0E0; symbol: _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb; size: 0x44.
int StageMemoryToVRAM(VRAMSubregion subregion, const void* data, unsigned int offset,
    unsigned int length, bool highPriority, bool allocateStagingSpace)
{
    return g_stagingManagerInstance.Stage(subregion, data, offset, length, highPriority, allocateStagingSpace);
}

// Original: arm9/main @ 0x020DC124; symbol: _Z23StageTexFilePaletteDataPV8NSBXXTexb; size: 0x60.
int StageTexFilePaletteData(volatile NSBXXTex* texture, bool highPriority)
{
    if (texture == NULL)
        return -1;
        
    texture->maybeBlock4Flags_32_ |= (1 << 0);

    int size = texture->block4NumEightBytes_;
    size <<= 3;
    int offset = (unsigned short)texture->block4VRAMLoadOffset_ << 3;
    const void* src = (const void*)((intptr_t)texture + texture->block4Offset_);

    return g_stagingManagerInstance.Stage(VRAMSubregion_TexturePalette,
        src, offset, size, highPriority, false);
}

// Original: arm9/main @ 0x020DC184; symbol: _Z21StageTexFileImageDataPV8NSBXXTexb; size: 0x64.
int StageTexFileImageData(volatile NSBXXTex* texture, bool highPriority)
{
    if (texture == NULL)
        return -1;
        
    texture->maybeBlock1Flags_10_ |= (1 << 0);

    int size = texture->block1NumEightBytes_;
    size <<= 3;
    int offset = (unsigned short)texture->block1VRAMLoadOffset_ << 3;
    const void* src = (const void*)((intptr_t)texture + texture->block1Offset_);

    return g_stagingManagerInstance.Stage(VRAMSubregion_TextureImage,
        src, offset, size, highPriority, false);
}

// Original: arm9/main @ 0x020DC1E8; symbol: _Z26CancelVRAMStagingOperationi; size: 0x18.
bool CancelVRAMStagingOperation(int id)
{
    return g_stagingManagerInstance.CancelTaskByID(id);
}

// Original: arm9/main @ 0x020DC200; symbol: _Z26UpdateVRAMStagingVRAMBanksv; size: 0x14.
void UpdateVRAMStagingVRAMBanks()
{
    g_stagingManagerInstance.UpdateBanks();
}