#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020D5158; symbol: func_020d5158; size: 0x50.
extern "C" bool WirelessCommand_ValidateThreeConfigurationBounds(unsigned char* p){if(*(unsigned short*)(p+4)>112)return false;unsigned n=*(unsigned short*)(p+24);if(n<10||n>1000)return false;n=*(unsigned short*)(p+50);if(n<1||n>14)return false;return true;}
