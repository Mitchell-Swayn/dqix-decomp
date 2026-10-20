#include <globaldefs.h>
ARM
extern "C" int NetworkSocket_Close(int);
extern "C" void _Z19SleepCurrentContextj(unsigned);
// Original: arm9/ov031 @ 0x022413C8; symbol: func_ov031_022413c8; size: 0x3C.
extern "C" void Http_CloseSocketAndWait(void *unused, int status) {
    int current = NetworkSocket_Close(status);
    if (current == -26) {
        do {
            _Z19SleepCurrentContextj(0x1f4);
            current = NetworkSocket_Close(status);
        } while (current == -26);
    }
}
