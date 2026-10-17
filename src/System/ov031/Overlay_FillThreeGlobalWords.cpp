#include <globaldefs.h>
THUMB
extern "C" unsigned char data_ov031_0224f670[];
extern "C" volatile unsigned char data_ov031_0224b114[];
extern "C" int Time_GetScaledCurrentTimestamp(int);
// Original: arm9/ov031 @ 0x02222AA4; symbol: func_ov031_02222aa4; size: 0x38.
extern "C" int Overlay_FillThreeGlobalWords(void* out) {
    *(unsigned*)out = *(unsigned*)(data_ov031_0224f670 + 0x38);
    int value = *(volatile int*)(data_ov031_0224b114 + 0xc);
    if (value == -1) {
        *(int*)((char*)out + 4) = -1;
    } else {
        value = *(volatile int*)(data_ov031_0224b114 + 0xc) - Time_GetScaledCurrentTimestamp(-1);
        *(int*)((char*)out + 4) = value;
    }
    *(unsigned*)((char*)out + 8) = *(unsigned*)(data_ov031_0224f670 + 0x78);
    return 1;
}
