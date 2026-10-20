#include <globaldefs.h>
ARM
extern "C" void Field_FinalizeEncounterParticipants(unsigned int, unsigned int, unsigned int, void *);
// Original: arm9/ov017 @ 0x021C9B58; symbol: func_ov017_021c9b58; size: 0x1C.
extern "C" void Network_ApplyEncounterParticipantResult(void *first, unsigned char *record) {
    Field_FinalizeEncounterParticipants(*(unsigned short *)(record + 6), 0, record[0xa], first);
}
