#include <globaldefs.h>
ARM
extern "C" void Filesystem_CancelStoredBackgroundTasks(void *);
extern "C" void *SystemState_GetGlobalFlags(void);
extern "C" void SystemState_ClearFlags(unsigned int *, unsigned int);
// Original: arm9/ov003 @ 0x021749C0; symbol: func_ov003_021749c0; size: 0x30.
extern "C" void Shop_CancelItemDetailLoads(void *object) {
    Filesystem_CancelStoredBackgroundTasks((char *)object + 0x3c);
    unsigned int flags = *(unsigned short *)((char *)object + 0x1000 + 0x46);
    flags &= ~0x800;
    *(unsigned short *)((char *)object + 0x1000 + 0x46) = (unsigned short)flags;
    SystemState_ClearFlags((unsigned int *)SystemState_GetGlobalFlags(), 1);
}
