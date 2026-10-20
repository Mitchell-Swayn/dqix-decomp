#include <globaldefs.h>
ARM
extern "C" void Graphics_CopyIndexedScreenRectangle(void *, unsigned int, unsigned int, unsigned int, short, short, short, short, unsigned short);
extern "C" void Graphics_CleanAndTransferScreenBuffer(char *, void *);
// Original: arm9/ov000 @ 0x02175480; symbol: ConfigureCoordinateRecordAndUpdateChild; size: 0x60.
// Dispatches the coordinate record at p +0x8C4 with dimensions 0x20 by 0x19 and color 0xFFFF, then updates that child resource.
extern "C" void BattleMenu_RefreshPartyPanelTilemap(char *p) {
    Graphics_CopyIndexedScreenRectangle(p + 0xc4 + 0x800, 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
    Graphics_CleanAndTransferScreenBuffer(p + 0xc4 + 0x800, 0);
}
