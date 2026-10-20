#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetEnabledTransfersAndRefreshWidget(void *object);
// Original: arm9/ov017 @ 0x021B6B74; symbol: func_ov017_021b6b74; size: 0x18.
extern "C" void Field_RefreshPartyManagementTransfersAndWidget(void *object) {
    void *nested = *(void **)((char *)object + 0x24);
    if (nested)
        Graphics_ResetEnabledTransfersAndRefreshWidget(nested);
}
