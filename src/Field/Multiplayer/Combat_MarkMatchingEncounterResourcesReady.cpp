#include <globaldefs.h>
ARM
extern "C" void *FieldBattle_GetEncounterRequest(void *);
extern "C" void *FieldBattle_GetScene(void *);
extern "C" void BattleScene_EnableFlags(unsigned char *, unsigned int);
// Original: arm9/ov017 @ 0x021C8BAC; symbol: EnableField55F4BitForMatchingEmbeddedId; size: 0x58.
// Requires active object and matching embedded/input IDs, then enables bit 0x02000000 on the nonnull field at +0x6AC.
extern "C" void Combat_MarkMatchingEncounterResourcesReady(void *unused0, void *input, void *unused2, unsigned char *base) {
    unsigned char *object = *(unsigned char **)(base + 0x3718);
    if (object[2] == 0) return;
    void *embedded = FieldBattle_GetEncounterRequest(object);
    if (embedded == 0) return;
    if (*(unsigned short *)((char *)embedded + 8) != *(unsigned short *)((char *)input + 4)) return;
    unsigned char *field = (unsigned char *)FieldBattle_GetScene(object);
    if (field == 0) return;
    BattleScene_EnableFlags(field, 0x02000000);
}
