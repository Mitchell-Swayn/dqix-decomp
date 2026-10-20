#include <globaldefs.h>
ARM
extern "C" void TextLayout_DrawSelectionPanelAndCursor(void*, unsigned);
// Original: arm9/ov017 @ 0x021A9248; symbol: func_ov017_021a9248; size: 0x14.
extern "C" void Field_DrawTravelDestinationMenu(void* p) { TextLayout_DrawSelectionPanelAndCursor((char*)p + 0x2c, 0); }
