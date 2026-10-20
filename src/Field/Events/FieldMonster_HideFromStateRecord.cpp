#include <globaldefs.h>
ARM
extern "C" void Field_FinalizeEncounterParticipants(unsigned int, unsigned int, unsigned int, void *);
// Original: arm9/ov017 @ 0x021C9CB0; symbol: FieldMonster_HideFromStateRecord; size: 0x28.
// Forwards the state record ID at +4 and the nonzero test of byte +6 to the field-monster hide routine.
extern "C" void FieldMonster_HideFromStateRecord(void *first, unsigned char *record) {
    Field_FinalizeEncounterParticipants(*(unsigned short *)(record + 4), 1, record[6] != 0, first);
}
