#include <globaldefs.h>
ARM
extern "C" void *Combat_FindIndexedMonsterObject(void *, int);
extern "C" int Combatant_TestPrimaryStatusFlagBit26(void *);
extern "C" int Combatant_TestTargetCapabilityBit2(void *);
// Original: arm9/ov024 @ 0x021F2064; symbol: func_ov024_021f2064; size: 0x54.
extern "C" int GameState_WriteValueIfObjectHasEligibleDescriptor(void **owner, short value, void *unused, int *outFlag, short *outValue) {
    void *object = Combat_FindIndexedMonsterObject(*owner, value);
    if (!object) return 0;
    if (Combatant_TestPrimaryStatusFlagBit26(object)) return 0;
    if (!Combatant_TestTargetCapabilityBit2(object)) return 0;
    *outValue = value;
    *outFlag = 1;
    return 1;
}
