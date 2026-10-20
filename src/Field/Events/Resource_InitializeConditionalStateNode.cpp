#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original: arm9/ov017 @ 0x021C0760; symbol: Resource_InitializeConditionalStateNode; size: 0x70.
// Initializes a 0x29 state node and resets its allocator pointer; for enabled nodes, clears state fields and sets two halfword sentinels to -1.
extern "C" void Resource_InitializeConditionalStateNode(unsigned char* node,unsigned char enabled) {
    LinkedQueue_InitializeNodeStatus(node); node[0]=0x29; node[0xbc]=enabled;
    *(unsigned*)(node+0x20)=0; node[0x24]=0; *(unsigned*)(node+0x1c)=0;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(node+8);
    if (!node[0xbc]) return;
    node[0x25]=0; node[0x26]=0;
    *(short*)(node+0x28)=-1; *(short*)(node+0x2a)=-1; *(short*)(node+0xa8)=0;
    *(unsigned*)(node+0xac)=0; *(unsigned*)(node+0xb0)=0; *(unsigned*)(node+0xb4)=0; *(unsigned*)(node+0xb8)=0;
}
