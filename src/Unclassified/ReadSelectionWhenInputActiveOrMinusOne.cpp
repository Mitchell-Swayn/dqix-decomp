#include <globaldefs.h>
extern "C" {
    extern unsigned char data_02114e54[];
    extern char data_02114e30[];
    int Object_TestNewlySetHalfwordMask(void *,int);
// Original: arm9/main @ 0x020E2918; symbol: func_020e2918; size: 0x6C.
    int ReadSelectionWhenInputActiveOrMinusOne(signed char *p){
        if(data_02114e54[85]||Object_TestNewlySetHalfwordMask(data_02114e30,1)||Object_TestNewlySetHalfwordMask(data_02114e30,1024)||Object_TestNewlySetHalfwordMask(data_02114e30,512))return p[21];
        return -1;
    }
}
