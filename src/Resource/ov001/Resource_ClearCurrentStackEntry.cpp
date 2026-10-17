#include <globaldefs.h>
ARM
extern "C" unsigned char *GameResources_GetInstance(void);
extern "C" void func_ov027_021d8c20(void *entry);
extern "C" void PopGlobalStackAndOptionallyNotify(int enabled);
// Original: arm9/ov001 @ 0x02161A60; symbol: func_ov001_02161a60; size: 0x30.
extern "C" int Resource_ClearCurrentStackEntry(void) {
    unsigned char *resources = GameResources_GetInstance() + 0x3000;
    unsigned char *entry = *(unsigned char **)(resources + 0x734);
    func_ov027_021d8c20(*(void **)(entry + 0x160));
    *(unsigned **)(entry + 0x160) = 0;
    PopGlobalStackAndOptionallyNotify(1);
    return 1;
}
