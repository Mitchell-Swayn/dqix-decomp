#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x02163200; symbol: Script_CopyResourceByte107ToTypeThreeRecord; size: 0x28.
// Reads resource table byte +0x107 and passes it to the type-three record setter.
extern "C" unsigned Script_ReadSceneLeaderFlagSnapshot(void *output) {
    char *resources = (char *)GameResources_GetInstance();
    char *table = *(char **)(resources + 0x3734);
    Script_WriteIntegerReferenceOutput(output, *(unsigned char *)(table + 0x107));
    return 1;
}
