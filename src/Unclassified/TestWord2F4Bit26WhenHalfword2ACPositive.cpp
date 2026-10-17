#include <globaldefs.h>
ARM
struct Flags { unsigned int low:26;unsigned int active:1;unsigned int high:5; };
// Original: arm9/main @ 0x02085644; symbol: func_02085644; size: 0x2C.
 extern "C" bool TestWord2F4Bit26WhenHalfword2ACPositive(unsigned char* p) { if (*(short*)(p+0x2ac)<=0)return false;return ((Flags*)(p+0x2f4))->active!=0; }
