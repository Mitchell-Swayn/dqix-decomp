#include <globaldefs.h>

extern "C" void InitializeFourWordsWithInvalidIndex(unsigned int *); extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
ARM
// Original: arm9/ov017 @ 0x021BA90C; symbol: func_ov017_021ba90c; size: 0x40.
extern "C" void InitializeType16Record(void *record) { unsigned char *p=(unsigned char *)record; InitializeFourWordsWithInvalidIndex((unsigned int *)record); p[0]=0x10; p[0x22]=0; _ZN13SafeAllocator21ResetAllocatorPointerEv(p+8); *(unsigned int *)(p+0x1c)=0; p[0x20]=0; p[0x21]=0; p[0x23]=0xff; }
