#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    int System_SetDisplayPowerAndWaitForIPC(int,void *,int,bool);
// Original: arm9/main @ 0x020CEDC0; symbol: func_020cedc0; size: 0x20.
    int IPC_SendNormalizedBooleanModeCommand(int mode){
        if(mode!=1)mode=0;
        return System_SetDisplayPowerAndWaitForIPC(mode,0,0,true);
    }
}
