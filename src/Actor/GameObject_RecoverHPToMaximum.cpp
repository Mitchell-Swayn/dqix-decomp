#include <globaldefs.h>
struct CounterPair { unsigned char padding[0x130]; volatile unsigned short* current; volatile unsigned short* limit; };
// Original: arm9/main @ 0x02048260; symbol: func_02048260; size: 0x24.
extern "C" int GameObject_RecoverHPToMaximum(CounterPair* pair)
{
    volatile unsigned short* current = pair->current;
    volatile unsigned short* limit = pair->limit;
    unsigned short oldValue = current[2];
    unsigned short newValue = *(volatile unsigned short*)((volatile unsigned char*)limit + 0x30);
    int difference = (int)newValue - (int)oldValue;
    if (difference <= 0) return 0;
    current[2] = newValue;
    return difference;
}
