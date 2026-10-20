#include <globaldefs.h>
ARM
struct TextEntry { unsigned short key; char pad2[2]; signed char owner; char pad5; unsigned short time; signed char status[4]; };
extern "C" {
int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
void* Network_GetConnectionManager();
bool Network_IsParentOrOffline(void*);
unsigned Network_TestMemberDisconnectFlag(void*,int);
void PartySync_ResetRecord(void*);
void Object_EmitMatchedTextEntryPacket(unsigned);
void Network_QueueEncounterFinalization(unsigned,int);
// Original data: arm9/main @ 0x20e8a4c; symbol: data_020e8a4c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const char ClearIndexedTextRecordStatesAndNotify_UnknownRoleInitializedBytes[];
}
inline bool HasClearedStatuses(TextEntry* p) { return RuntimeMemory_CompareByteRanges(p->status,ClearIndexedTextRecordStatesAndNotify_UnknownRoleInitializedBytes,4)==0; }
inline signed char* EntryStatuses(TextEntry* p) { return p->status; }
// Original: arm9/main @ 0x0207DBA8; symbol: func_0207dba8; size: 0x148.
extern "C" void Network_UpdateTextEntryTimeoutsAndStatus(TextEntry* entries) {
 void* state=_ZN9GameState11GetInstanceEv();
 TextEntry* node=entries;
 for(int i=0;i<4;i++,node++) {
  unsigned key=node->key;
  if(key && node->owner<0) {
   if(node->time<1000) node->time+=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);
   else if(HasClearedStatuses(node)) {
    Network_QueueEncounterFinalization(key,0);
    PartySync_ResetRecord(node);
   }
  } else node->time=0;
 }
 void* connection=Network_GetConnectionManager();
 if(!Network_IsParentOrOffline(connection)) return;
 for(int key=1;key<4;key++) {
  if(Network_TestMemberDisconnectFlag(connection,key)) {
   TextEntry* node=entries;
   for(int i=0;i<4;node++,i++) {
    signed char* statuses=EntryStatuses(node);
    if(node->key && statuses[key]==-1) {
     statuses[key]=0;
     Object_EmitMatchedTextEntryPacket(node->key);
    }
   }
  }
 }
}
