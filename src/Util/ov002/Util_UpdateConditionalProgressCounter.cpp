#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short* p,unsigned int mask);
extern "C" int AreByteFields5DSetAnd5EClear(unsigned char *p);
extern "C" unsigned int ReadWordFieldAtOffset1C();
extern "C" unsigned short data_02114e30[];
extern "C" unsigned char data_02114e54[];
// Original: arm9/ov002 @ 0x0216885C; symbol: func_ov002_0216885c; size: 0x9C.
extern "C" void Util_UpdateConditionalProgressCounter(unsigned char *self) {
    char *context = (char*)ReadWordFieldAtOffset1C();
    if (*(int*)(context + 0x998)) {
        if (self[0x2454] >= self[0x2455]) ++*(int*)(self + 0x1bc0);
        if (*(int*)(context + 0x9a0) == 3) {
            if (Object_TestNewlySetHalfwordMask(data_02114e30, 0x603) || AreByteFields5DSetAnd5EClear(data_02114e54))
                --*(int*)(self + 0x1bc0);
        }
    } else {
        ++*(int*)(self + 0x1bc0);
    }
}
