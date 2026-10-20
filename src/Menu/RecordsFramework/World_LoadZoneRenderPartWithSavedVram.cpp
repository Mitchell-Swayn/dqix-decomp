#include <globaldefs.h>
ARM
struct Tree; struct Item; struct State; struct SafeAllocator;
extern "C" Tree* Menu_FindSessionArenaById(Tree* tree, unsigned id);
extern "C" Item* Menu_FindVramSnapshotById(State* self, unsigned id);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void _ZN23ZoneContainerRenderPart5ResetEv(void*);
extern "C" void ZoneRenderPart_LoadSerializedDataWithAllocator(void *p,const void *data,int unused,SafeAllocator *alloc);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
extern "C" void Object_InvokeSaveTextureImageVRAMState(char *p);
// Original: arm9/ov023 @ 0x021F7290; symbol: func_ov023_021f7290; size: 0x88.
extern "C" void World_LoadZoneRenderPartWithSavedVram(char *self, State *state, const void *data, int length) {
    if (!data || !length) return;
    char *allocator = (char*)Menu_FindSessionArenaById((Tree*)state, *(unsigned short*)(self + 8));
    char *vram = (char*)Menu_FindVramSnapshotById(state, *(unsigned short*)(self + 10));
    if (!allocator || !vram) return;
    _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(allocator + 4);
    Graphics_RestoreTextureImageAndPaletteVRAMState(vram + 4);
    _ZN23ZoneContainerRenderPart5ResetEv(self + 0x20);
    ZoneRenderPart_LoadSerializedDataWithAllocator(self + 0x20, data, length, (SafeAllocator*)(allocator + 4));
    Object_InvokeSaveTextureImageVRAMState(vram + 4);
    _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(allocator + 4);
}
