#include <globaldefs.h>
ARM
extern "C" char* FieldBattle_GetScene(void*);
extern "C" char* FieldBattle_GetCombatContext(void*);
extern "C" char* FieldBattle_GetEncounterRequest(void*);
// Original: arm9/ov017 @ 0x021C5E28; symbol: func_ov017_021c5e28; size: 0x58.
// Queues the encounter rejection and resets its shared record only on the parent or offline side.
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsParentOrOffline(void*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
extern "C" void* PartySync_GetSharedRecordTable();
extern "C" void PartySync_ResetEntryByKey(void*,unsigned short);
extern "C" void PartySync_QueueEncounterRejectionAndReset(int member,int key) {
 if(Network_IsParentOrOffline(Network_GetConnectionManager())) {
 void* queue=Network_GetCommandRecordPool();
 unsigned char message[20];
 message[0]=0x3e;
 message[4]=member;
 *(unsigned short*)(message+6)=key;
 Network_QueueOutgoingRecord(queue,message,0);
 PartySync_ResetEntryByKey(PartySync_GetSharedRecordTable(),key);
 }
}
