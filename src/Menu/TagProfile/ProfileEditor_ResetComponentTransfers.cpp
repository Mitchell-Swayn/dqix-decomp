#include <globaldefs.h>
extern "C" void Menu_ResetSecondaryPanelResourceTransfers(void*);
extern "C" void Window_ResetResourceTransfers(void*);
extern "C" void Menu_RasterizeCenteredMessageSpriteText(void*);
// Release profile-screen components, including the optional UI manager.
// Original: arm9/ov012 @ 0x02185AB8; symbol: func_ov012_02185ab8; size: 0x38.
extern "C" void ProfileEditor_ResetComponentTransfers(unsigned char* screen) {
    Menu_ResetSecondaryPanelResourceTransfers(screen + 0xd28);
    if (screen[0x1371]) Window_ResetResourceTransfers(screen + 0xac);
    Menu_RasterizeCenteredMessageSpriteText(screen);
}
