#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Object3D_LoadPendingCHRResourcesAndClearStaging(int);
// Original: arm9/main @ 0x020579EC; symbol: func_020579ec; size: 0x24.
extern "C" void ObjectPool_ReloadPendingTemplateArchives(int *head) {
    int node = *head;
    while (node != 0) {
        Object3D_LoadPendingCHRResourcesAndClearStaging(node);
        node = *(int *)(node + 0x1ec);
    }
}
