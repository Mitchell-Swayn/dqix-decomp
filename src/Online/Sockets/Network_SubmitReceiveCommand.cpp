#include <globaldefs.h>
ARM
extern "C" int Network_SubmitSocketCommand(void *, char *);

// Original: arm9/ov031 @ 0x0220527C; symbol: func_ov031_0220527c; size: 0x10.
extern "C" int Network_SubmitReceiveCommand(void *object, char *request) {
    return Network_SubmitSocketCommand(*(void **)((unsigned char *)object + 0x64), request);
}
