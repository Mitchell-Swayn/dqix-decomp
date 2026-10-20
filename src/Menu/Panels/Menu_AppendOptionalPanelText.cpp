#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormatString(char *p, const char *text);
// Original: arm9/ov023 @ 0x021E8CC0; symbol: func_ov023_021e8cc0; size: 0x1C.
extern "C" void Menu_AppendOptionalPanelText(void *object) {
    const char *text = *(const char **)((char *)object + 0x5fc);
    if (text)
        Text_AppendFormatString(*(char **)((char *)object + 0x5d8), text);
}
