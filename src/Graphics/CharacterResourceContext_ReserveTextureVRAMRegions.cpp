#include <globaldefs.h>
extern "C" void TextureVRAM_SnapshotAllocationBounds(int);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(int);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(int, int, int);
extern "C" void Object_InvokeSaveTextureImageVRAMState(int);
// Original data: arm9/main @ 0x20e7ce0; symbol: data_020e7ce0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 40080000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int CharacterResourceContextReserveTextureVRAMRegions_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x20e7ce4; symbol: data_020e7ce4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 600000000004000040000000000800004000000000000000000000000004000040000000c0010000400000000002000040000000000800004000000000040000 ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int CharacterResourceContextReserveTextureVRAMRegions_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/main @ 0x020543EC; symbol: func_020543ec; size: 0x78.
extern "C" void CharacterResourceContext_ReserveTextureVRAMRegions(int object, int context) {
    TextureVRAM_SnapshotAllocationBounds(context);
    Graphics_RestoreTextureImageAndPaletteVRAMState(context);
    for (int index=0; index<10; ++index)
        VRAM_SaveStateAndReserveImagePaletteBytes(object+0xcc+index*0x70,*(int*)((char*)CharacterResourceContextReserveTextureVRAMRegions_UnknownRoleInitializedBytes+index*8),*(int*)((char*)CharacterResourceContextReserveTextureVRAMRegions_UnknownRoleInitializedBytes_Variant2+index*8));
    VRAM_SaveStateAndReserveImagePaletteBytes(object+0x568,0x240,0x20);
    Object_InvokeSaveTextureImageVRAMState(context);
}
