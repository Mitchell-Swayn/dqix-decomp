#include <globaldefs.h>
ARM
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" unsigned short FieldBattle_GetLifecyclePhase(char*);
extern "C" void Field_QueueEncounterControlHandshake(int, unsigned short);
// Original: arm9/ov017 @ 0x021CBF54; symbol: HandleMatchingFieldMonsterStateParameter; size: 0x64.
// For matching embedded and parameter IDs, routes parameter mode 0 to the helper unless state is 2, or writes state 2 at object +0x6C7 for mode 1.
extern "C" void HandleMatchingFieldMonsterStateParameter(void*, unsigned char* parameter, void*, unsigned char* owner) {
    unsigned char* object = *(unsigned char**)(owner + 0x3718);
    unsigned char* embedded = (unsigned char*)FieldBattle_GetEncounterRequest(object);
    if (*(unsigned short*)(embedded + 8) != *(unsigned short*)(parameter + 6)) return;
    if (parameter[4] == 0) {
        if (FieldBattle_GetLifecyclePhase((char*)object) == 2) return;
        Field_QueueEncounterControlHandshake(1, *(unsigned short*)(parameter + 6));
        return;
    }
    if (parameter[4] == 1) object[0x6c7] = 2;
}
