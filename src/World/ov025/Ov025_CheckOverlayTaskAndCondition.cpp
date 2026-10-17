#include <globaldefs.h>
extern "C" unsigned char data_ov025_021ef988[];
extern "C" int func_ov025_021ed0fc(unsigned char*);
extern "C" unsigned ReadOverlayControlSecondWord();
extern "C" int func_ov000_02162954();
// Original: arm9/ov025 @ 0x021E62C8; symbol: func_ov025_021e62c8; size: 0x3C.
extern "C" ARM int Ov025_CheckOverlayTaskAndCondition() {
    unsigned char* object = *(unsigned char**)(data_ov025_021ef988 + 0xc);
    if (!func_ov025_021ed0fc(object + 0x22c)) return 0;
    ReadOverlayControlSecondWord();
    return !func_ov000_02162954();
}
