#include <globaldefs.h>
ARM
extern "C" { int _ZNK6Script9Parameter5ToIntEv(const void*); float _ZNK6Script9Parameter7ToFloatEv(void*); char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned); void Overlay_EnqueueLinkedNode(void*); extern unsigned data_ov000_02184264[]; }
// Original: arm9/ov000 @ 0x0216C414; symbol: func_ov000_0216c414; size: 0x7C.
extern "C" int Resource_AllocateType100ScriptCommand(unsigned char* parameters) {
 char* record=_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],16);
 *(int*)record=0;
 *(int*)(record+4)=0;
 *(int*)record=100;
 *(short*)(record+8)=_ZNK6Script9Parameter5ToIntEv(parameters);
 *(short*)(record+10)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(parameters+8));
 *(short*)(record+12)=_ZNK6Script9Parameter5ToIntEv(parameters+16);
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
