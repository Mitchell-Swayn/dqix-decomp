#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void Ov017_InitializeStateRecord(void *);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *, unsigned int);
// Original: arm9/ov017 @ 0x021C1A98; symbol: func_ov017_021c1a98; size: 0x34.
extern "C" void Resource_SetLinkedNodeValueAndAppend(int ignored, unsigned int value) {
    unsigned char *resources = (unsigned char *)GameResources_GetInstance() + 0x3000;
    unsigned int *list = *(unsigned int **)(resources + 0x6FC);
    unsigned int *node = *(unsigned int **)(resources + 0xB78);
    Ov017_InitializeStateRecord(node);
    *(unsigned int *)((unsigned char *)node + 0x0C) = value;
    AppendLinkedNodeAndMarkActive(list, (unsigned int)node);
}
