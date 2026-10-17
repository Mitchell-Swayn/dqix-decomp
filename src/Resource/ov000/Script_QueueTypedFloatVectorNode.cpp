#include <globaldefs.h>
ARM
struct Node { int kind;void* next;unsigned short type;unsigned char mode,pad;float x,y,z; };
extern "C" unsigned int data_ov000_02184264[];
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned int,unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(Node*);
// Original: arm9/ov000 @ 0x0216A364; symbol: func_ov000_0216a364; size: 0xBC.
extern "C" int Script_QueueTypedFloatVectorNode(unsigned char* parameters,int count) {
Node* node=(Node*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],24);
node->kind=12;
node->type=_ZNK6Script9Parameter5ToIntEv(parameters);
node->mode=0;node->x=0;node->y=0;node->z=0;
parameters+=8;
if(node->type==5 || node->type==6)node->z=1.8f;
if(count>=2){node->mode=_ZNK6Script9Parameter5ToIntEv(parameters);parameters+=8;}
if(count>=3){node->x=_ZNK6Script9Parameter7ToFloatEv(parameters);node->y=_ZNK6Script9Parameter7ToFloatEv(parameters+8);node->z=_ZNK6Script9Parameter7ToFloatEv(parameters+16);}
Overlay_EnqueueLinkedNode(node);
return 1;
}
