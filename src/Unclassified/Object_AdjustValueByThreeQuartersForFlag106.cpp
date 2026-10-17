#include <globaldefs.h>
extern "C" int ReadWordFieldAtOffset150(int);
extern "C" int Object_ReadIndexedBitAtOffset8EC(int, int);
extern "C" unsigned int _ffltu(unsigned int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" unsigned int _fadd(unsigned int, unsigned int);
extern "C" unsigned int _ffixu(void);
// Original: arm9/main @ 0x020DD290; symbol: func_020dd290; size: 0x70.
extern "C" int Object_AdjustValueByThreeQuartersForFlag106(int object, int value) {
    if (object==0) return 0;
    if (value==0) return 0;
    int state=ReadWordFieldAtOffset150(object);
    if (state!=0 && Object_ReadIndexedBitAtOffset8EC(state,0x106)!=0) {
        unsigned int converted=_ffltu((unsigned int)value);
        converted=_fmul(0x3f400000,converted);
        _fadd(0x3f400000,converted);
        value=(int)_ffixu();
    }
    return value;
}
