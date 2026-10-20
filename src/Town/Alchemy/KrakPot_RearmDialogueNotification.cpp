#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x02159F94; symbol: func_ov006_02159f94; size: 0x1C.
extern "C" void KrakPot_RearmDialogueNotification(int a0) {
    if (*(int *)(a0 + 0x3ac) && *(int *)(a0 + 0x3a4))
        *(int *)(a0 + 0x3ac) = 0;
}
