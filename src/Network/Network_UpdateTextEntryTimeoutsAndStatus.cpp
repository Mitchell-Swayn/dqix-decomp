#include <globaldefs.h>
ARM
struct TextEntry { unsigned short key; char pad2[2]; signed char owner; char pad5; unsigned short time; signed char status[4]; };
extern "C" {
int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
void* Object_GetGlobalConnectionState();
bool TestInactiveOrPrimaryIndexState(void*);
unsigned Object_TestIndexedByte100EFlagByKey(void*,int);
void InitializeHalfwordKeyAndInvalidByteIds(void*);
void Object_EmitMatchedTextEntryPacket(unsigned);
void Object_QueueTypedRecordAndInitializeState(unsigned,int);
extern const char data_020e8a4c[];
}
inline bool HasClearedStatuses(TextEntry* p) { return RuntimeMemory_CompareByteRanges(p->status,data_020e8a4c,4)==0; }
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
    Object_QueueTypedRecordAndInitializeState(key,0);
    InitializeHalfwordKeyAndInvalidByteIds(node);
   }
  } else node->time=0;
 }
 void* connection=Object_GetGlobalConnectionState();
 if(!TestInactiveOrPrimaryIndexState(connection)) return;
 for(int key=1;key<4;key++) {
  if(Object_TestIndexedByte100EFlagByKey(connection,key)) {
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
