#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
extern "C" unsigned int String_CountBytesUntilTerminator(const signed char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" unsigned int data_ov002_0216d2fc;
// Original: arm9/ov002 @ 0x02168D10; symbol: func_ov002_02168d10; size: 0x44.
extern "C" void func_ov002_02168d10(char* object, const char* format) {
    if (format) {
        memset(object + 0xc, 0, 0x38);
        unsigned int length = String_CountBytesUntilTerminator((signed char*)(object + 0xc));
        sprintf(object + 0xc + length, (const char*)&data_ov002_0216d2fc, format);
    }
}
