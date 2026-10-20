#include <globaldefs.h>
ARM
extern "C" void TextLayout_DrawSelectionPanelAndCursor(void *, unsigned int);
// Original: arm9/ov017 @ 0x021A7998; symbol: func_ov017_021a7998; size: 0x14.
extern "C" void Field_DrawTravelConfirmationPanel(void *object) {
    TextLayout_DrawSelectionPanelAndCursor((char *)object + 0x24, 0);
}
