#include <globaldefs.h>
ARM
extern "C" unsigned char* ReadSignedWordAtOffset4();
// Original: arm9/main @ 0x02055108; symbol: func_02055108; size: 0x18.
 extern "C" unsigned int ReadResolvedRecordWordField14OrZero() { unsigned char* p=ReadSignedWordAtOffset4(); unsigned int result; if (p==0) result=0; else result=*(unsigned int*)(p+0x14); return result; }
