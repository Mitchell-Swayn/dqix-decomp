#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" unsigned short func_ov017_021bbc04(char *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x02163164; symbol: func_ov001_02163164; size: 0x40.
extern "C" int UpdateTypeThreeFromResourceFlag(void *object) {
    unsigned short active = func_ov017_021bbc04(*(char **)((char *)GameResources_GetInstance() + 0x3734));
    if (active) {
        SetNestedSecondWordForTypeThree(object, 1);
    } else {
        SetNestedSecondWordForTypeThree(object, 0);
    }
    return 1;
}
