#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B8B54; symbol: func_ov017_021b8b54; size: 0x18.
extern "C" int FieldBattle_IsSceneActive(void *object) {
    return *(unsigned short *)((unsigned char *)object + 0x6b4) == 0;
}
