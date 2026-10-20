#include <globaldefs.h>
extern "C" void Resource_ResetActiveOwnerState(unsigned);
extern "C" void Graphics_ResetCountedTransferEntriesWithModeZero(unsigned);
extern "C" void Window_SetWidgetPositionAndToggleTwoOptions(unsigned);
// Original: arm9/ov003 @ 0x02154FD0; symbol: func_ov003_02154fd0; size: 0x4C.
extern "C" ARM void Ov003_RefreshVisibleResourceWindows(void* state) {
    unsigned char* p = (unsigned char*)state;
    if (!p[0x1f8]) return;
    if (*(unsigned int*)(p + 0x204)) {
        Resource_ResetActiveOwnerState(*(unsigned int*)(p + 0x204));
    } else if (*(unsigned int*)(p + 0x18)) {
        Graphics_ResetCountedTransferEntriesWithModeZero(*(unsigned int*)(p + 0x18));
    }
    if (*(unsigned int*)(p + 0x1c))
        Window_SetWidgetPositionAndToggleTwoOptions(*(unsigned int*)(p + 0x1c));
}
