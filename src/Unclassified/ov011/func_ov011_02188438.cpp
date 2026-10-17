#include <globaldefs.h>
extern "C" unsigned data_02109bf4[];
extern "C" unsigned TestNonnegativeIdentifierWithByteOverride(unsigned*);
extern "C" void func_ov011_02184c68(void*, unsigned);
// Original: arm9/ov011 @ 0x02188438; symbol: func_ov011_02188438; size: 0x28.
extern "C" unsigned func_ov011_02188438(void* self) {
 unsigned value = TestNonnegativeIdentifierWithByteOverride(data_02109bf4);
 func_ov011_02184c68(self,value);
 return 1;
}
