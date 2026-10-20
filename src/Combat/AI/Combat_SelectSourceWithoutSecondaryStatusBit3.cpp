#include <globaldefs.h>
ARM
extern "C" void *Combat_FindIndexedMonsterObject(void *, int);
extern "C" int Combatant_TestSecondaryStatusFlagBit3(const void *);
// Original: arm9/ov024 @ 0x021F26FC; symbol: func_ov024_021f26fc; size: 0x40.
extern "C" int Combat_SelectSourceWithoutSecondaryStatusBit3(void **self, unsigned short value, int unused, int *status, unsigned short *outValue) {
    void *object = Combat_FindIndexedMonsterObject(*self, value);
    if (object == 0) return 0;
    if (Combatant_TestSecondaryStatusFlagBit3(object)) return 0;
    *outValue = value;
    *status = 1;
    return 1;
}
