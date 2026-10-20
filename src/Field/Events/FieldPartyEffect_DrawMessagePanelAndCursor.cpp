#include <globaldefs.h>
ARM
extern "C" void TextLayout_DrawSelectionPanelAndCursor(void *, unsigned);
// Original: arm9/ov017 @ 0x021ADC30; symbol: func_ov017_021adc30; size: 0x14.
extern "C" void FieldPartyEffect_DrawMessagePanelAndCursor(void *object) {
    TextLayout_DrawSelectionPanelAndCursor((char *)object + 0x44, 0);
}
