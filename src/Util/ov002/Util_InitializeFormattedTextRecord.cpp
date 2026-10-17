#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
extern "C" unsigned int String_CountBytesUntilTerminator(const signed char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" unsigned int data_ov002_0216d2fc;
// Original: arm9/ov002 @ 0x02168CA8; symbol: func_ov002_02168ca8; size: 0x68.
extern "C" void Util_InitializeFormattedTextRecord(char* p, char* source) {
    if (!source) return;
    unsigned int a = *(unsigned int*)source;
    *(unsigned int*)p = a;
    unsigned int b = *(unsigned int*)(source + 4);
    *(unsigned int*)(p + 4) = b;
    unsigned int c = *(unsigned int*)(source + 8);
    *(unsigned int*)(p + 4) = (unsigned int)(p + 0x44);
    *(unsigned int*)(p + 8) = c;
    const char* value = *(const char**)(source + 4);
    if (!value) return;
    memset(p + 0x44, 0, 0x200);
    unsigned int length = String_CountBytesUntilTerminator((signed char*)(p + 0x44));
    sprintf(p + 0x44 + length, (const char*)&data_ov002_0216d2fc, value);
}
