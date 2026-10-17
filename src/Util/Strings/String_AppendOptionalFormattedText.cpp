#include <globaldefs.h>
ARM
extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x020E46D8; symbol: func_020e46d8; size: 0x24.
extern "C" char* String_AppendOptionalFormattedText(char* p,const char** text){if(*text)p+=sprintf(p,*text);return p;}
