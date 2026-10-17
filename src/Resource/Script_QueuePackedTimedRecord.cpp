#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" int ReadOneOf204PackedTwoBitValues(volatile unsigned char*,int);
extern "C" void DecodePackedScriptParametersToLists(unsigned,int,void*,void*,void*);
extern "C" void PrependNodeToFieldA0List(unsigned char*,unsigned char*);
extern "C" char data_02109404[],data_02109418[];
struct Flag16 {unsigned short key:9,a:1,b:1,c:1,d:1,e:1,pad:2;};
struct Time32 {unsigned byte:8,hour:6,minute:5,pad:13;};
struct Node {unsigned short zone;Flag16 flags;Time32 time;void* lists[2];};
// Original: arm9/main @ 0x02094D88; symbol: func_02094d88; size: 0x25C.
extern "C" int Script_QueuePackedTimedRecord(char* params,int count) {
 int key=_ZNK6Script9Parameter5ToIntEv(params);
 int zone=_ZNK6Script9Parameter5ToIntEv(params+8);
 unsigned current=*(unsigned short*)(data_02109404+8);
 if(zone!=current) {
  if(current>=0xc3b5 && current<=0xc4e5) {if(zone!=0xc3b5)return 0;}
  else return 1;
 }
 int byte=_ZNK6Script9Parameter5ToIntEv(params+16);
 int hour=_ZNK6Script9Parameter5ToIntEv(params+24);
 int minute=_ZNK6Script9Parameter5ToIntEv(params+32);
 if(hour*100+minute>*(unsigned char*)(data_02109404+3)*100+*(unsigned char*)(data_02109404+4))return 0;
 int flag=_ZNK6Script9Parameter5ToIntEv(params+40);
 volatile unsigned char* state=(volatile unsigned char*)ReadGlobalValueAt02108844();
 int index=_ZNK6Script9Parameter5ToIntEv(params+48);
 if(index>=0) {
  int ready=(ReadOneOf204PackedTwoBitValues(state,index)==3)?1:0;
  if(!ready)return 0;
 }
 Node* node=(Node*)_ZN13SafeAllocator8AllocateEj(*(unsigned*)(data_02109404+0xc),16);
 node->zone=(unsigned short)zone;
 node->flags.key=(unsigned short)key;
 node->time.byte=byte;node->time.hour=hour;node->time.minute=minute;
 node->flags.a=(unsigned short)flag;
 node->flags.c=(unsigned short)_ZNK6Script9Parameter5ToIntEv(params+56);
 node->flags.b=(unsigned short)_ZNK6Script9Parameter5ToIntEv(params+64);
 int d=_ZNK6Script9Parameter5ToIntEv(params+72);
 char* final=params+80;
 node->flags.d=(unsigned short)d;
 node->flags.e=(unsigned short)_ZNK6Script9Parameter5ToIntEv(final);
 node->lists[0]=0;node->lists[1]=0;
 unsigned extra=0;
 DecodePackedScriptParametersToLists(*(unsigned*)(data_02109404+0xc),count-11,final+8,node->lists,&extra);
 PrependNodeToFieldA0List((unsigned char*)data_02109418,(unsigned char*)node);
 return 1;
}
