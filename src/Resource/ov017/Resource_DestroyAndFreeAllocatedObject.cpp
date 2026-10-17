#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalSixteenEntryDisplayState(void);
extern "C" void DispatchStoredResourceHandleAtOffsetC0(unsigned char* p);
extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int* p, int key);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void* self);
extern "C" void _ZN13SafeAllocator7DestroyEv(void* self);
extern "C" void Memory_FreeThroughAllocatorUnion(void* allocator, void* allocation);
extern "C" unsigned char data_02108760[];
extern "C" unsigned char data_02114e20[];
// Original: arm9/ov017 @ 0x021C310C; symbol: func_ov017_021c310c; size: 0x60.
extern "C" void Resource_DestroyAndFreeAllocatedObject(char* object) {
    if (*(int*)(object + 0x90) != 0) {
        void* display = Object_GetGlobalSixteenEntryDisplayState();
        DispatchStoredResourceHandleAtOffsetC0(data_02108760);
        RemoveMatchingNodeAndResetMatchingObjectSlots((int*)display, 0x11);
    }
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(object + 8);
    if (allocation == 0)
        return;
    _ZN13SafeAllocator7DestroyEv(object + 8);
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocation);
}
