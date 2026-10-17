#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0207959C; symbol: func_0207959c; size: 0x30.
extern "C" bool Object_TestEnabledPackedModeAtOffset17D(unsigned char* p,unsigned int mode) { unsigned char flags=p[0x17d];if(!(flags&8))return false;return ((unsigned char)((int)flags>>4)&3U)==mode; }
