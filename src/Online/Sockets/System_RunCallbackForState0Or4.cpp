#include <globaldefs.h>
ARM
extern "C" void ProcessRootObjectA4Entry(void);
// Original: arm9/ov031 @ 0x0220689C; symbol: System_RunCallbackForState0Or4; size: 0x30.
// Calls the state callback only when the signed nested state byte is 0 or 4.
extern "C" int System_RunCallbackForState0Or4(void *obj) {
    int shouldCall = 1;
    signed char state = *(signed char *)(*(unsigned int *)((char *)obj + 4) + 0x73);
    if (state != 0 && state != 4) shouldCall = 0;
    if (shouldCall) ProcessRootObjectA4Entry();
    return 0;
}
