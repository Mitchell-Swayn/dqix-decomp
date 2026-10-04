#include "System/RuntimeLocale.h"

#pragma define_section locale_data ".data" RW

// Original fixed-width, zero-padded C-locale text fields.
__declspec(section "locale_data") char data_020eecd4[4] = "";
char data_020eecd8[4] = "%T";
char data_020eecdc[8] = "AM|PM";

extern "C" int func_02001960(unsigned short*, const char*, unsigned int);
extern "C" int func_02001998(char*, unsigned short);
RuntimeCharacterMethods data_020eece4 = {func_02001960, func_02001998};
