#include <globaldefs.h>
#include <Resource/GameResources.h>
extern "C" void Memory_InitializeFlagAndSentinels(char *);
// Original: arm9/ov002 @ 0x0215A8CC; symbol: func_ov002_0215a8cc; size: 0x54.
extern "C" int Ov002_InitializeCurrentAndResourceRecords(char *object) {
    if (*(unsigned char *)(object + 0x253c) == 0) return 0;
    *(unsigned short *)(object + 0x1be0) = (unsigned short)*(unsigned int *)(object + 0x2540);
    *(unsigned short *)(object + 0x1bfe) = (unsigned short)*(unsigned int *)(object + 0x2544);
    Memory_InitializeFlagAndSentinels(object + 0x253c);
    char *resources = (char *)GameResources_GetInstance();
    Memory_InitializeFlagAndSentinels(*(char **)(resources + 0x371c) + 0x24);
    return 1;
}
