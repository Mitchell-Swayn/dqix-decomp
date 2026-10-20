#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    unsigned int Quest_TestBoundedIdFlag(void *,const void *,int);
// Original: arm9/main @ 0x02096088; symbol: func_02096088; size: 0x14.
    unsigned int Quest_TestCompletionFlag(unsigned char *p,int id){
        return Quest_TestBoundedIdFlag(p,p+132,id);
    }
}
