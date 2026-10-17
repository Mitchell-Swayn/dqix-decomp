#include <globaldefs.h>
ARM
extern "C" {extern unsigned data_ov000_02184264[];int _ZNK6Script9Parameter5ToIntEv(const void*);float _ZNK6Script9Parameter7ToFloatEv(void*);char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);void Overlay_EnqueueLinkedNode(void*);}
struct Command {unsigned type,next;unsigned char index;int angle;};
// Original: arm9/ov000 @ 0x0216D110; symbol: func_ov000_0216d110; size: 0x8C.
extern "C" int Script_QueueFixedRadianCommand8C(char* parameters){
Command* command=(Command*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],16);
command->type=0;command->next=0;command->type=0x8c;
command->index=_ZNK6Script9Parameter5ToIntEv(parameters);
float degrees=_ZNK6Script9Parameter7ToFloatEv(parameters+8);
command->angle=(int)(4096.0f*((3.1415927410125732f*degrees)/180.0f));
Overlay_EnqueueLinkedNode(command);return 1;
}
