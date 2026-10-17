#include <globaldefs.h>
extern "C" unsigned long long func_ov031_0221170c(void*);
extern "C" unsigned long long func_ov031_02212d20();
// Original: arm9/ov031 @ 0x02211608; symbol: func_ov031_02211608; size: 0x3C.
extern "C" ARM int Ov031_IsObjectTokenCurrent(void* object) {
    unsigned long long token = func_ov031_0221170c((char*)object + 0x10);
    if (token == 0) return 1;
    return token == func_ov031_02212d20();
}
