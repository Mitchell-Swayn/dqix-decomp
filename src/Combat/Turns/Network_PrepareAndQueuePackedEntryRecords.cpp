#include <globaldefs.h>
ARM
extern "C" void Network_QueueEncounterGroupSummary(void *);
extern "C" void QueueIndexedEntryMessages41(void *);
extern "C" void Combat_QueueGroupedExtendedCombatantIdentity(void *);
extern "C" void Network_QueueSelectedPackedEntryRecords(char *);
// Original: arm9/ov000 @ 0x0215E8E8; symbol: Network_PrepareAndQueuePackedEntryRecords; size: 0x30.
// Runs two overlay record preparation routines, then queues indexed messages and selected packed entry records from input+0x81b0.
extern "C" void Network_PrepareAndQueuePackedEntryRecords(unsigned char *p) {
    Network_QueueEncounterGroupSummary(p);
    QueueIndexedEntryMessages41(p);
    Combat_QueueGroupedExtendedCombatantIdentity(p + 0x81b0);
    Network_QueueSelectedPackedEntryRecords((char *)(p + 0x81b0));
}
