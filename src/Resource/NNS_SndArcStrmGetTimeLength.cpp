#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020BECD4; symbol: NNS_SndArcStrmGetTimeLength; size: 0x3C.
// Computes the nested rate scaled by one thousand, or zero for a null handle.
extern "C" unsigned NNS_SndArcStrmGetTimeLength(unsigned char* volatile* handle) {
 if (!*handle) return 0;
 unsigned char* nested=*handle;
 return (unsigned long long)*(unsigned*)(nested+0xcc)*1000ULL / (unsigned)*(unsigned short*)(nested+0xc4);
}
