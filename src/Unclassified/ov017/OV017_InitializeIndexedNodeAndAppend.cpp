#include <globaldefs.h>
extern "C" void *GameResources_GetInstance();
extern "C" void func_ov017_021a7328(signed char *);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned *, unsigned);
// Original: arm9/ov017 @ 0x021A72F4; symbol: func_ov017_021a72f4; size: 0x34.
extern "C" void OV017_InitializeIndexedNodeAndAppend(void *unused, unsigned value) {
    unsigned char *resources = (unsigned char *)GameResources_GetInstance() + 0x3000;
    unsigned *list = *(unsigned **)(resources + 0x6fc);
    signed char *node = *(signed char **)(resources + 0xb94);
    func_ov017_021a7328(node);
    *(unsigned *)(node + 0xc) = value;
    AppendLinkedNodeAndMarkActive(list, (unsigned)node);
}
