#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0207A014; symbol: func_0207a014; size: 0x4C.
    unsigned char *ClearFourTwelveByteBlocksAndReturnPointer(unsigned char *p){
        memset(p,0,12);
        memset(p+12,0,12);
        memset(p+24,0,12);
        memset(p+36,0,12);
        return p;
    }
}
