#include <globaldefs.h>
ARM
struct GameObject;
extern "C" GameObject *_Z16GetCombatantByIDii(int unused, int id);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(void *);
// Original: arm9/ov024 @ 0x021F0920; symbol: Combatant_IsRecordMask200ClearForId; size: 0x2C.
// Looks up the combatant by ID and returns true only when found with mask 0x200 clear at record offset 0x14.
extern "C" int Combatant_IsRecordMask200ClearForId(int *combatantId, int id) {
    GameObject *object = _Z16GetCombatantByIDii(*combatantId, id);
    if (object == 0) return 0;
    return Combatant_TestPrimaryStatusFlagBit9(object) == 0;
}
