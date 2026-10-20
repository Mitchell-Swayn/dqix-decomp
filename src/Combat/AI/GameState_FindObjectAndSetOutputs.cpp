#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" void* Combat_FindIndexedMonsterObject(void* table, int index);
extern "C" int Combatant_TestPrimaryStatusFlagBit20(LinkedDescriptorView* self);
extern "C" int Combatant_TestPrimaryStatusFlagBit21(LinkedDescriptorView* self);
// Original: arm9/ov024 @ 0x021F2548; symbol: func_ov024_021f2548; size: 0x54.
extern "C" int GameState_FindObjectAndSetOutputs(void** table, int index, void* unused, unsigned* found, short* outputIndex) {
    void* object = Combat_FindIndexedMonsterObject(*table, index);
    if (object == 0)
        return 0;
    if (Combatant_TestPrimaryStatusFlagBit20((LinkedDescriptorView*)object))
        return 0;
    if (Combatant_TestPrimaryStatusFlagBit21((LinkedDescriptorView*)object))
        return 0;
    *outputIndex = (short)index;
    *found = 1;
    return 1;
}
