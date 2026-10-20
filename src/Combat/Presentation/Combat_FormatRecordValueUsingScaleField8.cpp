#include <globaldefs.h>
ARM
extern "C" int Combat_FormatScaledValue(int value, char *buffer);
extern "C" void LoadAndRegisterLocalizedDisplayResource(char *buffer, int scale);
// Original: arm9/ov025 @ 0x021E4A58; symbol: Combat_FormatRecordValueUsingScaleField8; size: 0x30.
// Formats the integer at record +0xc into a local buffer, then passes the text and signed byte +8 to the string handler.
extern "C" int Combat_FormatRecordValueUsingScaleField8(unsigned char *p) {
    char buffer[0x50];
    Combat_FormatScaledValue(*(int *)(p + 0xc), buffer);
    LoadAndRegisterLocalizedDisplayResource(buffer, *(signed char *)(p + 8));
    return 1;
}
