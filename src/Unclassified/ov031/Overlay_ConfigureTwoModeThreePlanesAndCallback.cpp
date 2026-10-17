#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void Overlay_InitializeMainCallbackWhenBothContextsClear(void);
// Original: arm9/ov031 @ 0x02231088; symbol: func_ov031_02231088; size: 0x3C.
extern "C" void Overlay_ConfigureTwoModeThreePlanesAndCallback(void) {
    func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x14, 8);
    SetMainLoopCallback(Overlay_InitializeMainCallbackWhenBothContextsClear);
}
