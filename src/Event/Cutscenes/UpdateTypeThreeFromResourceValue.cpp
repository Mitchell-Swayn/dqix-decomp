#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x02161A1C; symbol: func_ov001_02161a1c; size: 0x44.
extern "C" int UpdateTypeThreeFromResourceValue(void *object) {
    char *resource = *(char **)((char *)GameResources_GetInstance() + 0x3734);
    if (*(unsigned *)((unsigned char *)resource + 0x160) == 0) {
        Script_WriteIntegerReferenceOutput(object, 1);
    } else {
        Script_WriteIntegerReferenceOutput(object, *(unsigned char *)(resource + 0x164));
    }
    return 1;
}
