#include <globaldefs.h>
ARM
struct State;
struct Owner;
extern "C" void Graphics_ResetCountedTransferEntriesWithModeZero(State* p);
extern "C" void Window_SetWidgetPositionAndToggleTwoOptions(Owner* self);
// Original: arm9/ov003 @ 0x02174890; symbol: func_ov003_02174890; size: 0x34.
extern "C" void Graphics_ResetEnabledTransfersAndWindow(char* object) {
    if (*(unsigned char*)(object + 0x103e) == 0) return;
    Graphics_ResetCountedTransferEntriesWithModeZero(*(State**)(object + 0x89c));
    if (*(Owner**)object == 0) return;
    Window_SetWidgetPositionAndToggleTwoOptions(*(Owner**)object);
}
