#include <globaldefs.h>
ARM
extern "C" volatile unsigned char data_ov031_0224e200[];
extern "C" volatile unsigned char data_ov031_022496a4[];
// Original: arm9/ov031 @ 0x022050C4; symbol: func_ov031_022050c4; size: 0x48.
extern "C" int Overlay_InvokeCallbackWhenProgressComplete(void) {
    int progress = *(volatile int*)(data_ov031_0224e200 + 0x20);
    int limit = *(volatile int*)(data_ov031_0224e200 + 0x18);
    if (progress < limit) return -1;
    void* argument = *(void* volatile*)data_ov031_0224e200;
    void* table = *(void* volatile*)data_ov031_022496a4;
    void (**callback)(void*) = (void (**)(void*))((char*)table + 0x1c);
    (*callback)(argument);
    *(volatile int*)data_ov031_0224e200 = 0;
    return 0;
}
