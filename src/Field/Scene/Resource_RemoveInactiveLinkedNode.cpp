#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
#pragma optimization_level 1
extern "C" void LinkedQueue_RemoveNodeAndResetStatus(int *param_1, int param_2);
extern "C" GameResources *GameResources_GetInstance();
// Original: arm9/ov017 @ 0x02197528; symbol: func_ov017_02197528; size: 0x34.
extern "C" void Resource_RemoveInactiveLinkedNode(void) {
    char *resources = (char *)GameResources_GetInstance() + 0x3000;
    int *node = *(int **)(resources + 0x734);
    int *list = *(int **)(resources + 0x6FC);
    if (*(unsigned char *)((char *)node + 2) == 0)
        return;
    if (*(unsigned char *)((char *)node + 3) != 0)
        return;
    LinkedQueue_RemoveNodeAndResetStatus(list, (int)node);
}
