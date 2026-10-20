#include <globaldefs.h>
extern "C" void LinkedQueue_InitializeNodeStatus(void*);
// Fields are identified by byte offsets; their higher-level roles are unknown.
// Original: arm9/ov017 @ 0x021be0a0; symbol: func_ov017_021be0a0; size: 0x24.
extern "C" void Field_InitializeGrottoDiscoveryCommand(unsigned char* p) {
    LinkedQueue_InitializeNodeStatus(p);
    p[0] = 0x33;
    *(unsigned*)(p + 8) = 0;
    *(unsigned*)(p + 0xc) = 0;
}
