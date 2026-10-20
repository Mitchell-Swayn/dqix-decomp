#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020D8550; symbol: func_020d8550; size: 0x2C.
extern "C" int Text_LowercaseASCIICharacter(int c) { bool upper=false; int byte=(unsigned char)c; if(byte>=65 && byte<=90) upper=true; if(upper)c+=32; return (signed char)c; }
