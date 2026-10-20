#include <globaldefs.h>
ARM
#pragma force_active on
// Original: arm9/ov031 @ 0x0220868C; symbol: func_ov031_0220868c; size: 0x24.
// Counts signed character bytes up to a dot or the string terminator.
extern "C" int Ssl_GetHostnameLabelLength(const char* text)
{
 const char* start=text;while(*text!='.'&&*text!=0)++text;return text-start;
}
