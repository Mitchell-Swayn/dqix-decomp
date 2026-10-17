#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02024D48; symbol: func_02024d48; size: 0x4C.
extern "C" int TestActiveByteAndOpenFlagCombination(unsigned char* p,int flag) { int result=1;bool open=true;unsigned char active=p[18];if(active && (!active || p[17]))open=false;if(!open && (!active || flag))result=0;return result; }
