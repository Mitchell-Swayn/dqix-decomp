#include <globaldefs.h>
extern "C" unsigned int _ffltu(unsigned int);
extern "C" unsigned int _fdiv(unsigned int, unsigned int);
extern "C" unsigned int _fadd(unsigned int, unsigned int);
// Original: arm9/main @ 0x02084FC8; symbol: func_02084fc8; size: 0x70.
extern "C" unsigned int SumActiveLinkedWord8Bits20To29DividedByTen(int base) {
    unsigned int divisor=0x41200000;
    unsigned int total=0;
    for (int index=0; index<11; ++index) {
        int entry=base+index*0x20;
        if (*(short*)(entry+0x1ac)>0) {
            unsigned int quantity=(unsigned int)(*(int*)(*(int*)(entry+0x194)+8)<<2)>>0x16;
            unsigned int fraction=_ffltu(quantity);
            fraction=_fdiv(fraction,divisor);
            total=_fadd(total,fraction);
        }
    }
    return total;
}
