#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" volatile unsigned char data_02109da4[];
extern "C" volatile unsigned char data_02109da6[];
extern "C" signed char data_020f1977[];
extern "C" void func_020a1940(int);
// Original: arm9/main @ 0x020A1F4C; symbol: func_020a1f4c; size: 0x5C.
extern "C" void PopGlobalStackAndOptionallyNotify(int enabled) {
    if (data_02109da4[1] == 0) return;
    data_02109da4[1] = data_02109da4[1] - 1;
    if (enabled != 0) {
        int count = data_02109da4[1];
        if (count != 0) {
            int index = (int)(signed char)data_02109da6[data_02109da4[1] - 1];
            func_020a1940((int)data_020f1977[index]);
        }
    }
}
