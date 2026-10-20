#include <globaldefs.h>
extern "C" {
    void *Zone3D_GetMainInstance();
    void GameObject_SetMotionStateAndRefreshAnimation(void *,int);
// Original: arm9/main @ 0x02076D34; symbol: func_02076d34; size: 0x28.
    bool FieldMonster_EnterStationaryAnimationMode(unsigned char *p){
        Zone3D_GetMainInstance();
        *(short *)(p+178)=0;
        GameObject_SetMotionStateAndRefreshAnimation(p,5);
        return true;
    }
}
