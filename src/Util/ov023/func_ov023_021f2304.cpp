#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
extern "C" unsigned int String_CountBytesUntilTerminator(const signed char *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" signed char data_ov023_021fe144[];
// Original: arm9/ov023 @ 0x021F2304; symbol: func_ov023_021f2304; size: 0x44.
extern "C" void func_ov023_021f2304(void *obj, unsigned value) {
    if (value == 0) return;
    memset((char *)obj + 0xc, 0, 0x38);
    unsigned int length = String_CountBytesUntilTerminator((signed char *)obj + 0xc);
    sprintf((char *)obj + 0xc + length, (const char *)data_ov023_021fe144, value);
}
