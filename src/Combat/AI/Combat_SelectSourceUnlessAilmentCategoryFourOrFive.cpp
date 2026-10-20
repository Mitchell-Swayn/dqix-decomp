#include <globaldefs.h>
extern "C" void *Combat_FindIndexedMonsterObject(void *, int, int, int *);
extern "C" int Ov024_TestNestedByteEqualFive();
extern "C" int Combatant_IsAilmentCategoryFour(void *);
// Original: arm9/ov024 @ 0x021F26A8; symbol: func_ov024_021f26a8; size: 0x54.
extern "C" int Combat_SelectSourceUnlessAilmentCategoryFourOrFive(void **objectField, unsigned short value, int key, int *flagOut, unsigned short *valueOut) {
    void *object = Combat_FindIndexedMonsterObject(*objectField, value, key, flagOut);
    if (!object) return 0;
    if (Ov024_TestNestedByteEqualFive()) return 0;
    if (Combatant_IsAilmentCategoryFour(object)) return 0;
    *valueOut = value;
    *flagOut = 1;
    return 1;
}
