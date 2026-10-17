#include <globaldefs.h>
extern "C" {
    void AppendKeyToGlobalTwentyFourHalfwordHistory(int);
// Original: arm9/main @ 0x02028C64; symbol: func_02028c64; size: 0x28.
    void SetHalfwordIdBitOrReportError(unsigned char *p,int id){
        if(id<16){
            *(unsigned short *)(p+4)|=1<<id;
            return;
        }AppendKeyToGlobalTwentyFourHalfwordHistory(5);
    }
}
