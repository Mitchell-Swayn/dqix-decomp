#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Selection_InitializeTouchAndDirectionalControls(void *);
// Original: arm9/main @ 0x0205C564; symbol: func_0205c564; size: 0xC.
    void Selection_ResetInputControls(void *p){
        Selection_InitializeTouchAndDirectionalControls(p);
    }
}
