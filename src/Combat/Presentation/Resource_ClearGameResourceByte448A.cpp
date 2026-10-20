#include <globaldefs.h>
ARM
#include <Resource/GameResources.h>

// Original: arm9/ov025 @ 0x021E8708; symbol: func_ov025_021e8708; size: 0x1C.
extern "C" int Resource_ClearGameResourceByte448A(void) {
    ((unsigned char *)GameResources_GetInstance())[0x448a] = 0;
    return 1;
}
