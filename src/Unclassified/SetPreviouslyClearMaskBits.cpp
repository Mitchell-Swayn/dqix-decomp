#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020483F0; symbol: func_020483f0; size: 0x28.
extern "C" bool SetPreviouslyClearMaskBits(unsigned char* p,unsigned int mask) { unsigned int* flags=*(unsigned int**)(p+0x130); unsigned int old=*flags; if ((mask&old)!=0) return false; *flags=(unsigned short)(old|mask); return true; }
