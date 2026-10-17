#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
struct Record {unsigned kind,next;unsigned hasValue:1,value:15,useDefault:1,hasSecond:1,rest:14;unsigned second:15,rest2:17;};
extern "C" void Overlay_EnqueueLinkedNode(Record*);
extern "C" unsigned data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216B564; symbol: func_ov000_0216b564; size: 0x148.
extern "C" int Script_QueueCommand37WithOptionalValues(unsigned char* args,int count) {
 Record* rec=(Record*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],16);
 if(!rec) return 0;
 rec->kind=0;
 rec->next=0;
 rec->kind=0x37;
 int first=_ZNK6Script9Parameter5ToIntEv(args);
 if(first<0) rec->hasValue=0;
 else if(first==0) {rec->hasValue=1;rec->value=1;}
 else {rec->hasValue=1;rec->value=first;}
 rec->useDefault=1;
 rec->hasSecond=0;
 rec->second=0;
 if(count>=2) {
  int second=_ZNK6Script9Parameter5ToIntEv(args+8);
  if(second>=0) {rec->useDefault=0;rec->hasSecond=1;rec->second=second;}
  else if(second!=-2) {rec->useDefault=0;rec->hasSecond=0;rec->second=0;}
 }
 Overlay_EnqueueLinkedNode(rec);
 return 1;
}
