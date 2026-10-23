#include <globaldefs.h>
ARM
extern "C" int Network_SubmitSocketCommand(void *, char *);
// Original: arm9/ov031 @ 0x0220528C; symbol: func_ov031_0220528c; size: 0x10.
extern "C" int Network_SubmitSendCommand(void *a0, char *request) {
    return Network_SubmitSocketCommand(*(void **)((char *)a0 + 0x68), request);
}
