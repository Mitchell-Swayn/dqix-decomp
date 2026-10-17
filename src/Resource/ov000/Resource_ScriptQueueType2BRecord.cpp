#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216B088; symbol: func_ov000_0216b088; size: 0x88.
extern "C" int Resource_ScriptQueueType2BRecord(unsigned char* p,int count){
 unsigned char* record=(unsigned char*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],16);
 *(int*)record=0;*(int*)(record+4)=0;
 *(int*)record=43;
 record[8]=_ZNK6Script9Parameter5ToIntEv(p);
 record[9]=_ZNK6Script9Parameter5ToIntEv(p+8);
 if(count>=3)*(int*)(record+12)=4096.0f*_ZNK6Script9Parameter7ToFloatEv(p+16);
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
