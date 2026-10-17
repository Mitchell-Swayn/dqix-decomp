#include <globaldefs.h>
#include <Util/Random.h>
extern "C" float _ffltu(unsigned short);
extern "C" float _fmul(float, float);
extern "C" float _fadd(float, float);
extern "C" unsigned short _ffixu();
// Original: arm9/main @ 0x02048934; symbol: func_02048934; size: 0x60.
extern "C" void ScaleItemHalfwordByRandomFactorAndCopyPair(void* out, void* item, Random* random) {
    if (item == 0) return;
    unsigned short value = *(unsigned short*)((char*)item + 0x5c);
    float randomValue = NextRandomFloatBetween(random, 0.8f, 1.0f);
    float converted = _ffltu(value);
    float scaled = _fmul(converted, randomValue);
    _fadd(0.5f, scaled);
    unsigned short result = _ffixu();
    *(unsigned short*)((char*)out + 0x188) = result;
    *(unsigned short*)((char*)item + 0x5e);
    *(unsigned short*)((char*)out + 0x18a) = *(unsigned short*)((char*)item + 0x5e);
}
