#include <globaldefs.h>
ARM
extern "C" void *data_ov017_021d83ac;
extern "C" int Network_AllocateAndEnqueueTypeNinetyFourNode(void *, int);
// Original: arm9/ov017 @ 0x021A5A68; symbol: func_ov017_021a5a68; size: 0x20.
extern "C" void Script_CallWithGlobalParameterIfPresent(int unused, int value) {
    void *parameter = data_ov017_021d83ac;
    if (parameter != 0)
        Network_AllocateAndEnqueueTypeNinetyFourNode(parameter, value);
}
