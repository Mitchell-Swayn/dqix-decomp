#include <globaldefs.h>
ARM
extern "C" void func_ov031_02231080(void);
extern "C" void func_ov031_02231084(void);
extern "C" int HasSharedObjectPointer(void);
extern "C" void Overlay_ConfigureTwoModeThreePlanesAndCallback(void);
extern "C" void SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x02231058; symbol: func_ov031_02231058; size: 0x28.
extern "C" void RegisterCallbackWhenSharedObjectAbsent(void) {
    func_ov031_02231080();
    func_ov031_02231084();
    if (!HasSharedObjectPointer())
        SetMainLoopCallback(Overlay_ConfigureTwoModeThreePlanesAndCallback);
}
