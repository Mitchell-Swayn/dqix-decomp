#include <globaldefs.h>
ARM
typedef void (*Callback)(void *, int);
// Original: arm9/ov031 @ 0x0223CA40; symbol: func_ov031_0223ca40; size: 0x14.
extern "C" void WfcUtility_ClearTextCanvas(void *p, int arg) {
    Callback callback = *(Callback *)((char *)*(void **)((char *)p + 0x14) + 4);
    callback(p, arg);
}
