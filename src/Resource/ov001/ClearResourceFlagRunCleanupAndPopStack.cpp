#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void Flags_ClearWordMask(unsigned int *, unsigned int);
extern "C" void func_ov028_021d9714(void);
extern "C" void PopGlobalStackAndOptionallyNotify(int);
// Original: arm9/ov001 @ 0x0216227C; symbol: func_ov001_0216227c; size: 0x24.
extern "C" int ClearResourceFlagRunCleanupAndPopStack(void) {
    Flags_ClearWordMask((unsigned int *)GameResources_GetInstance(), 0x1000);
    func_ov028_021d9714();
    PopGlobalStackAndOptionallyNotify(1);
    return 1;
}
