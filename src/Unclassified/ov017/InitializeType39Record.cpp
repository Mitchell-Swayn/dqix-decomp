#include <globaldefs.h>

extern "C" void InitializeFourWordsWithInvalidIndex(unsigned int *);
ARM
// Original: arm9/ov017 @ 0x021B11B0; symbol: func_ov017_021b11b0; size: 0x28.
extern "C" void InitializeType39Record(void *record) { unsigned char *p=(unsigned char *)record; InitializeFourWordsWithInvalidIndex((unsigned int *)record); p[0]=0x27; p[8]=0; p[0xa]=0; *(unsigned short *)(p+0xc)=0; }
