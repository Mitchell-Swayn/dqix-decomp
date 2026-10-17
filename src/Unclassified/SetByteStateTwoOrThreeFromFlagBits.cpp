#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0208CF98; symbol: func_0208cf98; size: 0x34.
    void SetByteStateTwoOrThreeFromFlagBits(unsigned char *p){
        unsigned short flags=*(unsigned short *)(p+218);
        if(flags&1){
            p[212]=2;
            p[213]=0;
            return;
        }if(flags&2){
            p[212]=3;
            p[213]=0;
        }
    }
}
