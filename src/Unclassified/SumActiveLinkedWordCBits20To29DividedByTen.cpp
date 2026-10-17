#include <globaldefs.h>
extern "C" unsigned int _ffltu(unsigned int);
extern "C" unsigned int _fdiv(unsigned int, unsigned int);
extern "C" unsigned int _fadd(unsigned int, unsigned int);
// Original: arm9/main @ 0x02084E78; symbol: func_02084e78; size: 0x70.
extern "C" unsigned int SumActiveLinkedWordCBits20To29DividedByTen(int base) {
    unsigned int divisor=0x41200000;
    unsigned int total=0;
    for (int index=0; index<11; ++index) {
        int entry=base+index*0x20;
        if (*(short*)(entry+0x1ac)>0) {
            int data=*(int*)(*(int*)(entry+0x194)+0xc);
            unsigned int quantity=((unsigned int)(data<<2))>>0x16;
            unsigned int fraction=_ffltu(quantity);
            fraction=_fdiv(fraction,divisor);
            total=_fadd(total,fraction);
        }
    }
    return total;
}
