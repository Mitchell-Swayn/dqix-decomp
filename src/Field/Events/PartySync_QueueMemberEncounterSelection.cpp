#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CA2A0; symbol: GameState_QueueTwoHalfwordRecord5A; size: 0x38.
// Builds a stack source record with tag 0x5a, two halfwords at +4/+6, and passes it with zero to MoveQueuedRecordAndApplySourceValue using ReadGlobalAt02100044; candidate stack lifetime differs. [2026-10-17 11:40 l14e] Builds a 0x5a-tagged queued record with two halfwords and submits it with zero using the shared global destination.
extern "C" void PartySync_QueueMemberEncounterSelection(unsigned short a, unsigned short b) {
 void *state = Network_GetCommandRecordPool();
 unsigned char record[0x14];
 record[0] = 0x5a;
 *(unsigned short *)(record + 4) = a;
 *(unsigned short *)(record + 6) = b;
 Network_QueueOutgoingRecord(state, record, 0);
}
