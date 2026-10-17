#include <globaldefs.h>
ARM

extern "C" void OverlayLoader_PushMappedOverlaySlot(unsigned int index);
extern "C" void *GameResources_GetInstance(void);
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int allocator, unsigned int size);
extern "C" void func_ov028_021d8b90(void *state);
extern "C" void func_ov028_021d8b44(void *state, void *data);
extern "C" unsigned int data_ov001_021658b8;

// Original: arm9/ov001 @ 0x021619BC; symbol: func_ov001_021619bc; size: 0x60.
extern "C" int Resource_AllocateOverlayStateBufferAndInitialize(void) {
    OverlayLoader_PushMappedOverlaySlot(5);
    char *resources = (char *)GameResources_GetInstance();
    char *list = *(char **)(resources + 0x3734);
    char *buffer = _ZN13SafeAllocator8AllocateEj(data_ov001_021658b8, 0x84);
    if (buffer == 0) {
        return 0;
    }
    *(char **)(list + 0x160) = buffer;
    list[0x164] = 0;
    func_ov028_021d8b90(buffer);
    func_ov028_021d8b44(buffer, (void *)data_ov001_021658b8);
    return 1;
}
