#include <globaldefs.h>
extern "C" void* _Z16GetCombatantByIDii(int, int);
extern "C" int CombatantState_CanApplyRotstopper(unsigned*);
extern "C" void CombatantState_ActivateRotstopper(unsigned char*);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int, int, int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_AppendResultMessage(int, void*, unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(int, void*, void*, int, int, int, bool);
// Original: arm9/ov024 @ 0x021DF0F0; symbol: ApplyPackedPartySelectionToCombatantRecord; size: 0xF8.
// Applies a packed party selection to a combatant record and dispatches the record update.
struct PackedPairA { unsigned unused:20; unsigned selected:10; unsigned reserved:2; };
struct PackedPairB { unsigned selected:10; unsigned middle:10; unsigned upper:10; unsigned reserved:2; };
extern "C" ARM void* ApplyPackedPartySelectionToCombatantRecord(void* self, int unused, int id, unsigned* descriptor, int arg4, int arg5, unsigned char activate) {
    void* combatant = _Z16GetCombatantByIDii(*(int*)((char*)self + 0x10), id);
    if (!combatant) return 0;

    bool useFirstPair = CombatantState_CanApplyRotstopper(*(unsigned**)((char*)combatant + 0x138)) && activate;
    unsigned short selected;
    if (useFirstPair) {
        CombatantState_ActivateRotstopper(*(unsigned char**)((char*)combatant + 0x138));
        PackedPairA* first = (PackedPairA*)((char*)descriptor + 0x20);
        PackedPairB* second = (PackedPairB*)((char*)descriptor + 0x24);
        selected = Combat_SelectMessageForPartyOrMonster(id, first->selected, second->selected);
    } else {
        PackedPairB* value = (PackedPairB*)((char*)descriptor + 0x24);
        selected = Combat_SelectMessageForPartyOrMonster(id, value->middle, value->upper);
    }

    void* record = Combat_ClearCurrentResultNodeSlot((unsigned char*)*(int*)((char*)self + 0x10));
    if (!record) return 0;
    Combat_AppendResultMessage(*(int*)((char*)self + 0x10), record, selected);
    unsigned char* options = *(unsigned char**)((char*)self + 0xc);
    bool active = ((unsigned)options[0x1c] << 24) >> 31;
    Combat_PopulateResultWithCurrentHealthAndMagic(*(int*)((char*)self + 0x10), record, combatant, 0, 0, 0, active);
    return record;
}
