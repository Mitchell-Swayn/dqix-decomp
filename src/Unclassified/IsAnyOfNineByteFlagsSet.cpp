#pragma optimization_level 4
#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02083BE8; symbol: func_02083be8; size: 0x30.
    bool IsAnyOfNineByteFlagsSet(unsigned char *p){
        for(int i=0;i<9;i++)if(p[0x910+i])return true;
        return false;
    }
}
