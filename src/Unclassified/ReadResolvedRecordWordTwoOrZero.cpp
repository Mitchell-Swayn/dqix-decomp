#include <globaldefs.h>
extern "C" {
unsigned int *ReadSignedWordAtOffset4();
// Original: arm9/main @ 0x020550C0; symbol: func_020550c0; size: 0x18.
unsigned int ReadResolvedRecordWordTwoOrZero(){unsigned int *p=ReadSignedWordAtOffset4();unsigned int result;if(p==0)result=0;else result=p[2];return result;}
}
