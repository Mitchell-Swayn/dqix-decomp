#include <globaldefs.h>
ARM
extern "C" bool _Z28GetTreasureMapTypeFromItemIDtPh(unsigned short,unsigned char*);
extern "C" void BattleScene_EnableFlags(unsigned char* p,unsigned int bits);
extern "C" void CombatScene_SetPendingRequestSelector(unsigned char*,int);
extern "C" void Grotto_QueueTreasureMapTypeSelection(void*,unsigned,unsigned,unsigned);
extern "C" void* FieldBattle_GetScene(void*);
extern "C" void* FieldBattle_GetEncounterRequest(void*);
struct Input { unsigned unused; unsigned short id,item; signed char value; };
struct MapType { unsigned char a,b; unsigned short c; };
// Original: arm9/ov017 @ 0x021CD510; symbol: func_ov017_021cd510; size: 0x80.
extern "C" void Grotto_ApplyMatchingTreasureMapRequest(void *unused, Input *input, void *unused2, char *owner) {
    void *context = *(void**)(owner + 0x3718);
    char *record = (char*)FieldBattle_GetEncounterRequest(context);
    if (*(unsigned short*)(record + 8) != input->id) return;
    MapType type;
    if (!_Z28GetTreasureMapTypeFromItemIDtPh(input->item, (unsigned char*)&type)) return;
    unsigned char *target = (unsigned char*)FieldBattle_GetScene(context);
    if (!target) return;
    Grotto_QueueTreasureMapTypeSelection(target, type.a, type.b, type.c);
    if (input->value >= 0) CombatScene_SetPendingRequestSelector(target, input->value);
    BattleScene_EnableFlags(target, 0x8000);
}
