#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" const signed char data_020e7039[];
extern "C" void func_0205afdc(void *, void *, int);
// Original: arm9/main @ 0x02026EBC; symbol: func_02026ebc; size: 0x4C.
extern "C" void Object_LinkIndexedFortyByteEntriesToContainer(void *object) {
    unsigned char i;
    for (i = 0; data_020e7039[i] >= 0; i++)
        func_0205afdc((char *)object + 0x94, (char *)object + 0xe8 + data_020e7039[i] * 0x28, 0);
}
