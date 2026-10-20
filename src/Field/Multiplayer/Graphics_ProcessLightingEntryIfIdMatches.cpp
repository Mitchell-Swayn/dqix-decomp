#include <globaldefs.h>
ARM
extern "C" void *FieldBattle_GetEncounterRequest(void *);
extern "C" void FieldBattle_MarkSceneSetupReady(void *);
// Original: arm9/ov017 @ 0x021CBC0C; symbol: func_ov017_021cbc0c; size: 0x3C.
extern "C" void Graphics_ProcessLightingEntryIfIdMatches(int ignored0, void *record, int ignored2, unsigned char *owner) {
    void *entry = *(void **)((unsigned char *)owner + 0x3718);
    void *embedded = FieldBattle_GetEncounterRequest(entry);
    if (embedded == 0) return;
    if (*(unsigned short *)((unsigned char *)embedded + 8) != *(unsigned short *)((unsigned char *)record + 4)) return;
    FieldBattle_MarkSceneSetupReady(entry);
}
