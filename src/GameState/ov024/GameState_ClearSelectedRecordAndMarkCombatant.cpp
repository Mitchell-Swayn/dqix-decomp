#include <globaldefs.h>
ARM
extern "C" void* _Z16GetCombatantByIDii(int, int);
extern "C" int IsWordField14FlagBitZeroClear_Main02089160(unsigned*);
extern "C" void* ClearCurrentIndexedRecord(unsigned char*);
extern "C" void Object_SetByte7CToThreeAndFlag800(unsigned char*);
// Original: arm9/ov024 @ 0x021E5E80; symbol: func_ov024_021e5e80; size: 0x44.
extern "C" void GameState_ClearSelectedRecordAndMarkCombatant(unsigned char* state, int index) {
    void* combatant = _Z16GetCombatantByIDii(*(int*)(state + 0x10), index);
    if (combatant == 0) return;
    if (!IsWordField14FlagBitZeroClear_Main02089160(*(unsigned**)((char*)combatant + 0x138))) return;
    if (ClearCurrentIndexedRecord(*(unsigned char**)(state + 0x10)) == 0) return;
    Object_SetByte7CToThreeAndFlag800(*(unsigned char**)((char*)combatant + 0x138));
}
