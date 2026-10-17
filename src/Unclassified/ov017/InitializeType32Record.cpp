#include <globaldefs.h>

extern "C" void InitializeFourWordsWithInvalidIndex(unsigned int *); extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *); extern "C" unsigned int data_ov017_021d8474;
ARM
// Original: arm9/ov017 @ 0x021C0124; symbol: func_ov017_021c0124; size: 0x3C.
extern "C" void InitializeType32Record(void *record, unsigned char value) { unsigned char *p=(unsigned char *)record; InitializeFourWordsWithInvalidIndex((unsigned int *)record); p[0]=0x20; _ZN13SafeAllocator21ResetAllocatorPointerEv(p+8); data_ov017_021d8474=0; *(unsigned int *)(p+0x1c)=0; p[0x20]=value; }
