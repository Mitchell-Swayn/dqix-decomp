#include <globaldefs.h>
ARM
struct Node;
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" void InitializeRecordAndInvalidHalfwordIndices(char*);
extern "C" void SelectNodeRankFromEntryFlags(Node**,Node*);
extern "C" void LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(char**,int);
extern "C" int ReadOneOf204PackedTwoBitValues(volatile unsigned char*,int);
extern "C" unsigned Object_ReadParitySelectedFlagForBoundedIndex(unsigned char*,int);
extern "C" unsigned TestOneOf204PackedNibbleHighFlags(unsigned char*,int);
struct Global { unsigned char first,second,third,pad; short previous,key,unknown; unsigned short sequence,slot,padE; char** list; unsigned allocator; };
extern "C" Global data_02108cec;
struct Flags { unsigned char phase:2,pad:4,active:1,pad2:1; };
inline bool IsStatus(unsigned char* global,int index,int status) { return ReadOneOf204PackedTwoBitValues(global,index)==status; }
// Original: arm9/main @ 0x0206CF58; symbol: func_0206cf58; size: 0x47C.
extern "C" int Script_QueueFilteredRecord(unsigned char* parameters,int count) {
unsigned char* global;
data_02108cec.sequence++;
int id=_ZNK6Script9Parameter5ToIntEv(parameters);
int condition=_ZNK6Script9Parameter5ToIntEv(parameters+8);
int lowerA=_ZNK6Script9Parameter5ToIntEv(parameters+16);
int lowerB=_ZNK6Script9Parameter5ToIntEv(parameters+24);
int lowerC=_ZNK6Script9Parameter5ToIntEv(parameters+32);
int upperA=_ZNK6Script9Parameter5ToIntEv(parameters+40);
int upperB=_ZNK6Script9Parameter5ToIntEv(parameters+48);
int upperC=_ZNK6Script9Parameter5ToIntEv(parameters+56);
int phase=_ZNK6Script9Parameter5ToIntEv(parameters+64);
int slot=_ZNK6Script9Parameter5ToIntEv(parameters+72);
int key=_ZNK6Script9Parameter5ToIntEv(parameters+80);
if(data_02108cec.key!=key) { data_02108cec.key=key;data_02108cec.unknown=-1;data_02108cec.previous=-1; }
global=(unsigned char*)ReadGlobalValueAt02108844();
if(data_02108cec.previous!=id && data_02108cec.previous>-1 && !IsStatus(global,id,1) && !IsStatus(global,id,2) && IsStatus(global,data_02108cec.previous,3) && IsStatus(global,id,3) && data_02108cec.previous>id) return 1;
switch(condition) {
case -1: if(!IsStatus(global,id,0)) return 1;break;
case 3: if(!IsStatus(global,id,1)) return 1;break;
case 0: if(!IsStatus(global,id,2)) return 1;break;
case 1: if(!Object_ReadParitySelectedFlagForBoundedIndex(global,id)) return 1;break;
case 2: if(!IsStatus(global,id,3)) return 1;break;
case 4: if(!TestOneOf204PackedNibbleHighFlags(global,id) || !IsStatus(global,id,0)) return 1;break;
}
int upper=upperA*1000+upperB*10+upperC;
int current=data_02108cec.third*1000+data_02108cec.second*10+data_02108cec.first;
int lower=lowerA*1000+lowerB*10+lowerC;
if(current<lower || upper<current) return 1;
void* gs=_ZN9GameState11GetInstanceEv();
if(phase==1) { if(_ZNK9GameState21IsMorningDayOrEveningEv(gs)) return 1; }
else if(phase==0) { if(!_ZNK9GameState21IsMorningDayOrEveningEv(gs)) return 1; }
if(slot!=data_02108cec.slot) {LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(data_02108cec.list,key);return 1;}
char* node=_ZN13SafeAllocator8AllocateEj(data_02108cec.allocator,0x78);
if(!node) return 0;
InitializeRecordAndInvalidHalfwordIndices(node);
*(short*)(node+0x46)=id;
node[4]=lowerA;node[5]=lowerB;node[6]=lowerC;node[7]=upperA;node[8]=upperB;node[9]=upperC;
((Flags*)(node+10))->phase=(unsigned char)phase;
*(short*)(node+2)=slot;
node[0]=key;
if(data_02108cec.key!=key) data_02108cec.key=key;
if(count<12) {LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(data_02108cec.list,key);data_02108cec.previous=id;return 1;}
char* next=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(parameters+88,node+16);
*(short*)(node+0x1c)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next));
if(count>15) node[0x1e]=_ZNK6Script9Parameter5ToIntEv(next+8);
*(unsigned short*)(node+0x44)=data_02108cec.sequence;
((Flags*)(node+10))->active=1;
SelectNodeRankFromEntryFlags((Node**)data_02108cec.list,(Node*)node);
data_02108cec.previous=id;
return 1;
}
