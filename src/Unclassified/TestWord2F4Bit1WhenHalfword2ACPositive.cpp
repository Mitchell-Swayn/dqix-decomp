#include <globaldefs.h>
ARM
struct Flags { unsigned int low:1;unsigned int active:1;unsigned int high:30; };
// Original: arm9/main @ 0x020850A4; symbol: func_020850a4; size: 0x2C.
 extern "C" bool TestWord2F4Bit1WhenHalfword2ACPositive(unsigned char* p) { if (*(short*)(p+0x2ac)<=0)return false;return ((Flags*)(p+0x2f4))->active!=0; }
