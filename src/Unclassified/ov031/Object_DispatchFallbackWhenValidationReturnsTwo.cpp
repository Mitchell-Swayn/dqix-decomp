#include <globaldefs.h>
extern "C" void func_ov031_02211ca0(void*, unsigned, unsigned, unsigned);
extern "C" int func_ov031_02211f24();
extern "C" int func_ov031_022130e8(void*, unsigned, unsigned, unsigned, unsigned);
extern "C" unsigned char data_ov031_0224e5b4[];
// Original: arm9/ov031 @ 0x02211D54; symbol: func_ov031_02211d54; size: 0x5C.
extern "C" int Object_DispatchFallbackWhenValidationReturnsTwo(void* a, unsigned b, unsigned c, unsigned d, unsigned e) {
    func_ov031_02211ca0(a, b, c, d);
    unsigned char* entry = *(unsigned char**)(data_ov031_0224e5b4 + 4);
    if (entry) entry[0xc] = 1;
    int result = func_ov031_02211f24();
    if (result != 2) return result;
    return func_ov031_022130e8(a, b, c, d, e);
}
