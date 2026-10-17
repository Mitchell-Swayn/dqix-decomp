#include <globaldefs.h>
ARM
#pragma always_inline on
struct Record {unsigned short key;char pad[2];signed char active;char pad2[3];signed char states[4];};
extern "C" {extern char data_020e8a4c[];int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);void InitializeHalfwordKeyAndInvalidByteIds(unsigned char*);void Object_EmitMatchedTextEntryPacket(unsigned);void Object_QueueTypedRecordAndInitializeState(unsigned,int);}
inline int IsEmpty(Record* p){return RuntimeMemory_CompareByteRanges(p->states,data_020e8a4c,4)==0;}
// Original: arm9/main @ 0x0207DA94; symbol: func_0207da94; size: 0xC4.
extern "C" void ClearIndexedTextRecordStatesAndNotify(Record* p,int slot){
for(int i=0;i<4;p++,i++){
if(p->states[slot]){
if(p->active<0)p->states[slot]=-1;
else{
int emit=p->states[slot]==-1;p->states[slot]=0;
if(emit)Object_EmitMatchedTextEntryPacket(p->key);
if(p->active==slot)p->active=-1;
if(IsEmpty(p)){Object_QueueTypedRecordAndInitializeState(p->key,0);InitializeHalfwordKeyAndInvalidByteIds((unsigned char*)p);}
}
}
}
}
