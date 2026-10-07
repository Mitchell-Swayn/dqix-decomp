#include <globaldefs.h>

extern "C" unsigned int data_020f01f8[];

extern "C" ARM unsigned int func_0204a5e4(unsigned int row, unsigned int column)
{
    unsigned int (*table)[4] = (unsigned int (*)[4])data_020f01f8;
    return table[row][column];
}
