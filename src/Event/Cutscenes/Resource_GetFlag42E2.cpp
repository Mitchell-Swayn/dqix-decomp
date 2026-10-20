#include <globaldefs.h>
ARM
#include <Resource/GameResources.h>

// Original: arm9/ov001 @ 0x02156858; symbol: func_ov001_02156858; size: 0x14.
extern "C" unsigned char Resource_GetFlag42E2(void) {
    return ((unsigned char *)GameResources_GetInstance())[0x42e2];
}
