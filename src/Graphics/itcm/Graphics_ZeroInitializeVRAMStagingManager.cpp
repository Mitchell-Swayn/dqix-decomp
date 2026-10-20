#include <globaldefs.h>
ARM
extern "C" void _ZN18VRAMStagingManager14ZeroInitializeEv(int);

// Original: arm9/itcm @ 0x01FF9718; symbol: func_01ff9718; size: 0x14.
extern "C" int Graphics_ZeroInitializeVRAMStagingManager(int manager) {
    _ZN18VRAMStagingManager14ZeroInitializeEv(manager);
    return manager;
}
