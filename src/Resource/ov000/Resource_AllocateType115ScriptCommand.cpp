#include <globaldefs.h>
ARM
extern "C" { int _ZNK6Script9Parameter5ToIntEv(const void*); char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned); void Overlay_EnqueueLinkedNode(void*); extern unsigned data_ov000_02184264[]; }
// Original: arm9/ov000 @ 0x0216C85C; symbol: func_ov000_0216c85c; size: 0x88.
extern "C" int Resource_AllocateType115ScriptCommand(unsigned char* parameters,int count) {
 char* record=_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],16);
 if(!record) return 0;
 unsigned short index;
 int value=_ZNK6Script9Parameter5ToIntEv(parameters);
 index=_ZNK6Script9Parameter5ToIntEv(parameters+8);
 unsigned char flag=0;
 if(count>=3) flag=_ZNK6Script9Parameter5ToIntEv(parameters+16);
 *(int*)(record+8)=value;
 *(unsigned short*)(record+12)=index-26;
 record[14]=flag;
 *(int*)record=115;
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
