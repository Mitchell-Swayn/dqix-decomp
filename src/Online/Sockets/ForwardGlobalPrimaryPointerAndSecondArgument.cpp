#include <globaldefs.h>
ARM
extern "C" void *Network_GetPrimarySocketCommandContext(void);
extern "C" void Network_SubmitSocketCommand(void *, unsigned int);
// Original: arm9/ov031 @ 0x0220529C; symbol: func_ov031_0220529c; size: 0x18.
extern "C" void ForwardGlobalPrimaryPointerAndSecondArgument(unsigned int unused, unsigned int value) {
    Network_SubmitSocketCommand(Network_GetPrimarySocketCommandContext(), value);
}
