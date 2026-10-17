#include <globaldefs.h>
ARM
extern "C" void * volatile data_ov031_0224e590;
extern "C" void func_ov031_02211864(int, int);
// Original: arm9/ov031 @ 0x02211440; symbol: func_ov031_02211440; size: 0x44.
extern "C" void SetPendingInputAndInvokeHandler(void *value) {
    void *state = data_ov031_0224e590;
    if (state == 0) return;
    *(void **)((unsigned char *)state + 4) = value;
    void (*handler)(void *) = *(void (**)(void *))((unsigned char *)data_ov031_0224e590 + 0x3c);
    if (handler != 0) handler(value);
    else func_ov031_02211864(9, -2);
}
