#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216ABC4; symbol: func_ov000_0216abc4; size: 0xA4.
extern "C" int Resource_ScriptQueueType1ERecord(unsigned char* p,int count){
 unsigned char* record=(unsigned char*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],16);
 if(count==1){
 *(int*)record=0;*(int*)(record+4)=0;*(int*)record=30;
 *(int*)(record+12)=_ZNK6Script9Parameter5ToIntEv(p);
 *(signed char*)(record+8)=-1;
 Overlay_EnqueueLinkedNode(record);
 }else if(count==2){
 *(int*)record=0;*(int*)(record+4)=0;*(int*)record=30;
 record[8]=_ZNK6Script9Parameter5ToIntEv(p);
 *(int*)(record+12)=_ZNK6Script9Parameter5ToIntEv(p+8);
 Overlay_EnqueueLinkedNode(record);
 }
 return 1;
}
