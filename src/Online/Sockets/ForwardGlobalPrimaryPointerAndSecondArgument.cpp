#include <globaldefs.h>
ARM
extern "C" void *Network_GetPrimarySocketCommandContext(void);
extern "C" int Network_SubmitSocketCommand(void *, char *);
// Original: arm9/ov031 @ 0x0220529C; symbol: func_ov031_0220529c; size: 0x18.
extern "C" int ForwardGlobalPrimaryPointerAndSecondArgument(void *unused, char *value) {
    return Network_SubmitSocketCommand(Network_GetPrimarySocketCommandContext(), value);
}
