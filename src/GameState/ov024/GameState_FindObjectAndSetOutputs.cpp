#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" void* FindIndexedGameStateObjectWithFlag400(void* table, int index);
extern "C" int TestLinkedDescriptorFlag00100000(LinkedDescriptorView* self);
extern "C" int TestLinkedDescriptorFlag00200000(LinkedDescriptorView* self);
// Original: arm9/ov024 @ 0x021F2548; symbol: func_ov024_021f2548; size: 0x54.
extern "C" int GameState_FindObjectAndSetOutputs(void** table, int index, void* unused, unsigned* found, short* outputIndex) {
    void* object = FindIndexedGameStateObjectWithFlag400(*table, index);
    if (object == 0)
        return 0;
    if (TestLinkedDescriptorFlag00100000((LinkedDescriptorView*)object))
        return 0;
    if (TestLinkedDescriptorFlag00200000((LinkedDescriptorView*)object))
        return 0;
    *outputIndex = (short)index;
    *found = 1;
    return 1;
}
