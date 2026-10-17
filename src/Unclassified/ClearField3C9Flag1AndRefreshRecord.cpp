#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void BackgroundLoader_RemoveStoredTaskAtOffset340(void *);
// Original: arm9/main @ 0x020939FC; symbol: func_020939fc; size: 0x18.
    void ClearField3C9Flag1AndRefreshRecord(unsigned char *p){
        p[0x3c9]&=~1;
        BackgroundLoader_RemoveStoredTaskAtOffset340(p);
    }
}
