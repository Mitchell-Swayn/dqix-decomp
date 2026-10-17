#include <globaldefs.h>
extern "C" {
int Object_TestNewlySetHalfwordMask(void*,unsigned);
void DispatchStoredHalfwordIndexWithTwoArguments(void*,int,int);
extern unsigned char data_02114e30[],data_02114e54[],data_02108760[];
}
// Original: arm9/ov019 @ 0x0218C240; symbol: func_ov019_0218c240; size: 0x50.
extern "C" int func_ov019_0218c240() {
    if (!Object_TestNewlySetHalfwordMask(data_02114e30,2035) && !data_02114e54[85]) return 0;
    DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
    return 1;
}
