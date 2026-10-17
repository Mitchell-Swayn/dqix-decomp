#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalSixteenEntryDisplayState();
extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int*, int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void SetByteFieldAtOffset253ToOne(void*);
extern "C" unsigned char data_02108760[];
extern "C" unsigned char data_02114e20[];
extern "C" void DispatchStoredResourceHandleAtOffsetC0(unsigned char*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" void func_020a0c0c();
struct DisplayObject { unsigned char pad[0x30]; unsigned char allocator[4]; };
// Original: arm9/ov017 @ 0x021A7280; symbol: func_ov017_021a7280; size: 0x5C.
extern "C" void CleanupDisplayObject(DisplayObject* object) {
    RemoveMatchingNodeAndResetMatchingObjectSlots((int*)Object_GetGlobalSixteenEntryDisplayState(), 0xd);
    SetByteFieldAtOffset253ToOne(_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv()));
    DispatchStoredResourceHandleAtOffsetC0(data_02108760);
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)object + 0x30);
    if (allocator != 0) {
        _ZN13SafeAllocator7DestroyEv((char*)object + 0x30);
        Memory_FreeThroughAllocatorUnion(data_02114e20, allocator);
    }
    func_020a0c0c();
}
