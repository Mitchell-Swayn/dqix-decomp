#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned data_ov000_02184264[];
struct Event { unsigned opcode; void* next; short x,y,z; unsigned char mode,pad; };
// Original: arm9/ov000 @ 0x0216CAD0; symbol: func_ov000_0216cad0; size: 0x1B8.
extern "C" int Script_QueueOpcode76FixedPointParameters(char* params,int count) {
 Event* event=(Event*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],16);
 if(!event) return 0;
 memset(event,0,16);
 event->mode=_ZNK6Script9Parameter5ToIntEv(params);
 params+=8;
 switch(event->mode) {
 case 0:case 2:
 event->x=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(params));
 event->y=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(params+8));
 event->z=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(params+16));
 break;
 case 1:case 4:
 event->x=0x28f;event->y=4096;event->z=0;
 if(count>=2) {
 float value=_ZNK6Script9Parameter7ToFloatEv(params);
 params+=8;
 int scale=(int)(4096.0f*value);
 event->x=((long long)event->x*scale+2048)>>12;
 }
 if(count>=3) {
 float value=_ZNK6Script9Parameter7ToFloatEv(params);
 params+=8;
 event->y=(int)(4096.0f*value);
 }
 if(count>=4) event->z=_ZNK6Script9Parameter5ToIntEv(params)<<12;
 break;
 case 3:
 event->x=1;event->y=0;event->z=0;
 if(count>=2) event->x=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(params));
 break;
 }
 event->opcode=0x76;
 Overlay_EnqueueLinkedNode(event);
 return 1;
}
