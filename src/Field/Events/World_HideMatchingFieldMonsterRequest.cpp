#include <globaldefs.h>
ARM
extern "C" int Network_GetLocalMemberId(char* p);
extern "C" void FieldMonster_HideByRecordIdentifier(void* owner, void* record);
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" void PrepareFieldMonsterContextForHide(void*);
// Original: arm9/ov017 @ 0x021C5E80; symbol: func_ov017_021c5e80; size: 0x80.
extern "C" void World_HideMatchingFieldMonsterRequest(void *unused, unsigned char *input, void *unused2, char *owner, char *state) {
    unsigned index = input[4];
    unsigned short id;
    unsigned char *context = *(unsigned char**)(owner + 0x3718);
    id = *(unsigned short*)(input + 6);
    if (index != Network_GetLocalMemberId(state)) {
        if (!context[2]) return;
        char *record = (char*)FieldBattle_GetEncounterRequest(context);
        if (!record) return;
        if (*(unsigned short*)(record + 8) != id) return;
        PrepareFieldMonsterContextForHide(context);
        FieldMonster_HideByRecordIdentifier(owner,(void*)id);
    } else {
        PrepareFieldMonsterContextForHide(context);
        FieldMonster_HideByRecordIdentifier(owner,(void*)id);
    }
}
