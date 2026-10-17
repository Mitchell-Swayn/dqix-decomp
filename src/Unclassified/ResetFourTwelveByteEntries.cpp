#include <globaldefs.h>
extern "C" {
    void InitializeHalfwordKeyAndInvalidByteIds(void *);
// Original: arm9/main @ 0x0207DE1C; symbol: func_0207de1c; size: 0x2C.
    unsigned char *ResetFourTwelveByteEntries(unsigned char *p){
        InitializeHalfwordKeyAndInvalidByteIds(p);
        InitializeHalfwordKeyAndInvalidByteIds(p+12);
        InitializeHalfwordKeyAndInvalidByteIds(p+24);
        InitializeHalfwordKeyAndInvalidByteIds(p+36);
        return p;
    }
}
