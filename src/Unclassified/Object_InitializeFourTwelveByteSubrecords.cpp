#include <globaldefs.h>
ARM
extern "C" void InitializeHalfwordKeyAndInvalidByteIds(void*);
// Original: arm9/main @ 0x0207D798; symbol: func_0207d798; size: 0x28.
extern "C" void Object_InitializeFourTwelveByteSubrecords(unsigned char* p){InitializeHalfwordKeyAndInvalidByteIds(p);InitializeHalfwordKeyAndInvalidByteIds(p+12);InitializeHalfwordKeyAndInvalidByteIds(p+24);InitializeHalfwordKeyAndInvalidByteIds(p+36);}
