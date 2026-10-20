#include <globaldefs.h>
ARM
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" void* FieldBattle_GetScene(void*);
extern "C" void CombatScene_ResetPartySelectionIfActive(void*);
// Original: arm9/ov017 @ 0x021CC080; symbol: func_ov017_021cc080; size: 0x4C.
extern "C" void OV017_ApplyMatchingEmbeddedOverride(void *unused0, unsigned char *query, void *unused2, char *owner) {
    void *object = *(void **)(owner + 0x3718);
    void *embedded = FieldBattle_GetEncounterRequest(object);
    void *value = FieldBattle_GetScene(object);
    if (!embedded) return;
    if (*(unsigned short *)((char *)embedded + 8) != *(unsigned short *)(query + 4)) return;
    if (!value) return;
    CombatScene_ResetPartySelectionIfActive(value);
}
