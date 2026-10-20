#include <globaldefs.h>
ARM
extern "C" void Field_FinalizeEncounterParticipants(unsigned short value, int zero1, int zero2, void *context);
// Original: arm9/ov017 @ 0x021C9B04; symbol: func_ov017_021c9b04; size: 0x1C.
extern "C" void Network_HandleEncounterRemovalCommand(void *context, void *record) {
    Field_FinalizeEncounterParticipants(*(unsigned short *)((char *)record + 6), 0, 0, context);
}
