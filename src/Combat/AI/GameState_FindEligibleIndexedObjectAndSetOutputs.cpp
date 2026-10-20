#include <globaldefs.h>
ARM
extern "C" void* Combat_FindIndexedMonsterObject(void*, unsigned short);
extern "C" int Combatant_TestPrimaryStatusFlagBit28(void*);
// Original: arm9/ov024 @ 0x021F5768; symbol: GameState_FindEligibleIndexedObjectAndSetOutputs; size: 0x40.
// Finds the indexed eligible object, then writes success and copies the requested halfword output.
extern "C" int GameState_FindEligibleIndexedObjectAndSetOutputs(void** list, unsigned short value, void* unused, int* resultFlag, unsigned short* resultValue) {
    void* object = Combat_FindIndexedMonsterObject(*list, value);
    if (!object) return 0;
    if (Combatant_TestPrimaryStatusFlagBit28(object)) return 0;
    *resultFlag = 1;
    *resultValue = value;
    return 1;
}
