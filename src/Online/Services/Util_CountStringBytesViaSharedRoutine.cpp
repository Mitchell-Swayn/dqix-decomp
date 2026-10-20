#include <globaldefs.h>
ARM
extern "C" unsigned int String_CountBytesUntilTerminator(const char *);
// Original: arm9/ov031 @ 0x0223FB48; symbol: func_ov031_0223fb48; size: 0xC.
extern "C" unsigned int Util_CountStringBytesViaSharedRoutine(const char *p) { return String_CountBytesUntilTerminator(p); }
