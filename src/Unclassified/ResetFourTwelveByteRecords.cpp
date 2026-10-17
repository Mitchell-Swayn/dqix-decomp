#include <globaldefs.h>
ARM
extern "C" void InitializeHalfwordKeyAndInvalidByteIds(void*);
// Original: arm9/main @ 0x0207DDF0; symbol: func_0207ddf0; size: 0x2C.
extern "C" void* ResetFourTwelveByteRecords(unsigned char* p){InitializeHalfwordKeyAndInvalidByteIds(p);InitializeHalfwordKeyAndInvalidByteIds(p+12);InitializeHalfwordKeyAndInvalidByteIds(p+24);InitializeHalfwordKeyAndInvalidByteIds(p+36);return p;}
