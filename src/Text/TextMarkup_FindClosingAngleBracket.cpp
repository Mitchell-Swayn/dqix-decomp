#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020424AC; symbol: func_020424ac; size: 0x38.
extern "C" signed char* TextMarkup_FindClosingAngleBracket(signed char* p) { if(p) { for(;*p;p++) if(*p==62 && p[1]!=62)return p; }return 0; }
