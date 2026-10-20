#include <globaldefs.h>
ARM
extern "C" int Ssl_ReceiveAndProcessRecord(void *object);
// Original: arm9/ov031 @ 0x0220A444; symbol: func_ov031_0220a444; size: 0x30.
extern "C" int Ssl_ReceiveChangeCipherSpecAndFinished(void *object) {
    if (Ssl_ReceiveAndProcessRecord(object) != 7)
        return 1;
    return Ssl_ReceiveAndProcessRecord(object) != 6;
}
