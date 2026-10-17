#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" void GameObject_InitializeType3DEntry(void*);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned*, unsigned);
// Original: arm9/ov017 @ 0x021A65C4; symbol: func_ov017_021a65c4; size: 0x44.
extern "C" void Resource_InitializeAndAppendNode(void* unused, unsigned char type, int active) {
    unsigned char* resources = (unsigned char*)GameResources_GetInstance() + 0x3000;
    unsigned* list = *(unsigned**)(resources + 0x6fc);
    unsigned char* node = *(unsigned char**)(resources + 0xb8c);
    GameObject_InitializeType3DEntry(node);
    node[0xc] = type;
    if (active) node[0xb] = 1;
    AppendLinkedNodeAndMarkActive(list, (unsigned)node);
}
