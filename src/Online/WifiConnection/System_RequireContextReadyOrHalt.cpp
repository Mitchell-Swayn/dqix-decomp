#include <globaldefs.h>
ARM

extern "C" void Multiboot_SetParentState(unsigned short);
extern "C" int Network_SetParentStartFlagAndInvokeHandler(void *);
extern "C" int Multiboot_LoadAndRegisterDownloadImage(void *);
extern "C" void DisableInterruptsAndHaltForever(void);

// Original: arm9/ov031 @ 0x022387F4; symbol: func_ov031_022387f4; size: 0x48.
extern "C" void System_RequireContextReadyOrHalt(void *state, void *context) {
    Multiboot_SetParentState(2);
    if (Network_SetParentStartFlagAndInvokeHandler(context) != 0) {
        Multiboot_SetParentState(7);
        return;
    }
    if (Multiboot_LoadAndRegisterDownloadImage(state) == 0) {
        DisableInterruptsAndHaltForever();
    }
}
