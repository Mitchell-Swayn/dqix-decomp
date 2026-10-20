#include <globaldefs.h>
ARM
#pragma always_inline on
struct Record {unsigned short key;char pad[2];signed char active;char pad2[3];signed char states[4];};
// Original data: arm9/main @ 0x20e8a4c; symbol: data_020e8a4c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char ClearIndexedTextRecordStatesAndNotify_UnknownRoleInitializedBytes[];int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);void PartySync_ResetRecord(unsigned char*);void Object_EmitMatchedTextEntryPacket(unsigned);void Network_QueueEncounterFinalization(unsigned,int);}
inline int IsEmpty(Record* p){return RuntimeMemory_CompareByteRanges(p->states,ClearIndexedTextRecordStatesAndNotify_UnknownRoleInitializedBytes,4)==0;}
// Original: arm9/main @ 0x0207DA94; symbol: func_0207da94; size: 0xC4.
extern "C" void ClearIndexedTextRecordStatesAndNotify(Record* p,int slot){
for(int i=0;i<4;p++,i++){
if(p->states[slot]){
if(p->active<0)p->states[slot]=-1;
else{
int emit=p->states[slot]==-1;p->states[slot]=0;
if(emit)Object_EmitMatchedTextEntryPacket(p->key);
if(p->active==slot)p->active=-1;
if(IsEmpty(p)){Network_QueueEncounterFinalization(p->key,0);PartySync_ResetRecord((unsigned char*)p);}
}
}
}
}
