#include <globaldefs.h>
ARM
extern "C" int Field_FinalizeEncounterParticipants(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov017 @ 0x021C9B74; symbol: func_ov017_021c9b74; size: 0x1C.
extern "C" int Network_HandleEncounterRemovalNotification(unsigned int a, unsigned short* b) { return Field_FinalizeEncounterParticipants(b[3], 0, 0, a); }
