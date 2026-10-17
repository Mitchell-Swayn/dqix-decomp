#include <globaldefs.h>
struct CopyWords22 { unsigned words[22]; };
struct CopyLayout {
    unsigned short field00;
    unsigned char field02;
    unsigned char field03;
    unsigned short field04;
    unsigned short field06;
    unsigned field08;
    unsigned short field0c;
    unsigned field10;
    unsigned field14;
    unsigned short halfwords18[6];
    unsigned field24;
    unsigned char field28;
    unsigned char field29;
    unsigned short field2a;
    CopyWords22 words2c;
};
#pragma always_inline on
// Original: arm9/main @ 0x02070EE0; symbol: func_02070ee0; size: 0xB8.
extern "C" ARM void* CopyLayoutAndReturnDestination(void* destination, const void* source)
{
    *(CopyLayout*)destination = *(const CopyLayout*)source;
    return destination;
}
