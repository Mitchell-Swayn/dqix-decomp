#include <globaldefs.h>
ARM
struct GameResources;
extern "C" GameResources *GameResources_GetInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x02161A90; symbol: func_ov001_02161a90; size: 0x28.
extern "C" int Grotto_SetTypeThreeValueFromGameResources(void *object) {
    char *resources = (char *)GameResources_GetInstance();
    int value = *(int *)(*(int *)(resources + 0x3734) + 0x15c);
    Script_WriteIntegerReferenceOutput(object, value);
    return 1;
}
