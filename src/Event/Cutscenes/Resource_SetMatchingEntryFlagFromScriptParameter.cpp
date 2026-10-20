#include <globaldefs.h>
ARM

extern "C" void *GameResources_GetInstance(void);
extern "C" int Script_ReadParameterAsInteger(void *parameter);

// Original: arm9/ov001 @ 0x02161DB0; symbol: func_ov001_02161db0; size: 0x50.
extern "C" int Resource_SetMatchingEntryFlagFromScriptParameter(void *parameter) {
    char *resources = (char *)GameResources_GetInstance();
    char *table = *(char **)(resources + 0x3734);
    int value = Script_ReadParameterAsInteger(parameter);
    char *node = *(char **)(table + 0xd0);
    while (node != 0) {
        if ((unsigned char)node[1] == value) {
            node[4] = (unsigned char)node[4] | 1;
            break;
        }
        node = *(char **)(node + 0x34);
    }
    return 1;
}
