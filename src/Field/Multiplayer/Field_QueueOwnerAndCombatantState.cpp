#include <globaldefs.h>
ARM
extern "C" void QueueTag75EmbeddedResourceValues(void*,void*);
extern "C" void Network_QueueEncounterGroupSummary(void*);
extern "C" void QueueIndexedEntryMessages41(char*);
extern "C" void Combat_QueueEncounterControlByte(void*);
extern "C" void Combat_QueueGroupedExtendedCombatantIdentity(char*);
extern "C" void Network_QueueSelectedPackedEntryRecords(char*);
extern "C" void Combat_QueueGroupedExtendedCombatantState(char*);
extern "C" void QueueGroupedCombatantStatusRecords(char*);
extern "C" void Combat_QueueGroupedExtendedCombatantValueBanks(char*);
extern "C" void Combat_QueueGroupedExtendedCombatantTailBanks(char*);
extern "C" void Combat_QueueFourEnabledCombatantDetailRecords();
extern "C" void GameState_QueueActiveCombatantRecords();
extern "C" void GameState_QueueSelectedCombatantStateRecords();
extern "C" void Combat_QueuePartyComponentFlags();
extern "C" void Network_QueueActiveCombatantPackedRecords();
extern "C" void Combat_QueueCombatantPackedFields();
extern "C" void GameState_ApplyQueuedRecordValue(void*);

// Original: arm9/ov017 @ 0x021CDF80; symbol: QueueOwnerAndCombatantStateRecords; size: 0x94.
// Queues owner, embedded packed records and active combatant state, then applies queued record value.
extern "C" void Field_QueueOwnerAndCombatantState(char* owner,void* other){
QueueTag75EmbeddedResourceValues(owner,other);
Network_QueueEncounterGroupSummary(owner);
QueueIndexedEntryMessages41(owner);
Combat_QueueEncounterControlByte(other);
Combat_QueueGroupedExtendedCombatantIdentity(owner+0x81b0);
Network_QueueSelectedPackedEntryRecords(owner+0x81b0);
Combat_QueueGroupedExtendedCombatantState(owner+0x81b0);
QueueGroupedCombatantStatusRecords(owner+0x81b0);
Combat_QueueGroupedExtendedCombatantValueBanks(owner+0x81b0);
Combat_QueueGroupedExtendedCombatantTailBanks(owner+0x81b0);
Combat_QueueFourEnabledCombatantDetailRecords();
GameState_QueueActiveCombatantRecords();
GameState_QueueSelectedCombatantStateRecords();
Combat_QueuePartyComponentFlags();
Network_QueueActiveCombatantPackedRecords();
Combat_QueueCombatantPackedFields();
GameState_ApplyQueuedRecordValue(owner);
}
