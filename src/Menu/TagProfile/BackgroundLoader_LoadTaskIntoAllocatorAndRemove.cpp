#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void* _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*, int, void**, unsigned*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void ResourceStringTable_CopySerializedData(void*, void*, void*, unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
// Original: arm9/ov012 @ 0x02185F04; symbol: func_ov012_02185f04; size: 0x70.
extern "C" void BackgroundLoader_LoadTaskIntoAllocatorAndRemove(void* object) {
    void* game = _ZN9GameState11GetInstanceEv();
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    void* data;
    unsigned size;
    _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, *(int*)((char*)object + 0x1388), &data, &size);
    void* allocator = (char*)object + 0x84;
    _ZN13SafeAllocator5ResetEv(allocator);
    ResourceStringTable_CopySerializedData((char*)object + 0x1344, allocator, data, size);
    _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)((char*)object + 0x1388));
    *(int*)((char*)object + 0x1388) = -1;
}
