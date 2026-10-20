#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char*);
// Original: arm9/ov017 @ 0x021B6790; symbol: func_ov017_021b6790; size: 0x48.
// Initializes type-23 linked node, embedded SafeAllocator and invalid sentinel bytes.
// Individual flag and sentinel meanings remain unresolved.
extern "C" void InitializeType23LinkedNode(unsigned char* node) {
 LinkedQueue_InitializeNodeStatus((signed char*)node);
 node[0]=23;
 *(unsigned*)(node+0x24)=0;
 node[0x1f]=0;
 node[0x1c]=0;
 ((SafeAllocator*)(node+8))->ResetAllocatorPointer();
 node[0x1d]=0;
 node[0x1e]=255;
 *(signed char*)(node+0x20)=-1;
}
