#include <globaldefs.h>
extern "C" void SnapshotBlockAndVolatileWordPair(int);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(int);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(int, int, int);
extern "C" void Object_InvokeSaveTextureImageVRAMState(int);
extern "C" int data_020e7ce0[];
extern "C" int data_020e7ce4[];
// Original: arm9/main @ 0x020543EC; symbol: func_020543ec; size: 0x78.
extern "C" void InitializeElevenContextBoundedResourceRegions(int object, int context) {
    SnapshotBlockAndVolatileWordPair(context);
    Graphics_RestoreTextureImageAndPaletteVRAMState(context);
    for (int index=0; index<10; ++index)
        VRAM_SaveStateAndReserveImagePaletteBytes(object+0xcc+index*0x70,*(int*)((char*)data_020e7ce0+index*8),*(int*)((char*)data_020e7ce4+index*8));
    VRAM_SaveStateAndReserveImagePaletteBytes(object+0x568,0x240,0x20);
    Object_InvokeSaveTextureImageVRAMState(context);
}
