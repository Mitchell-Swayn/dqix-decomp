#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void ClearField18Flag2AndBytes6CAnd8F(void *);
// Original: arm9/main @ 0x02088C74; symbol: func_02088c74; size: 0x28.
    void Object_SetByte6DToFiveAndFlag4ThenUpdateState(unsigned char *p){
        p[109]=5;
        p[144]=0;
        *(int *)(p+24)|=4;
        ClearField18Flag2AndBytes6CAnd8F(p);
    }
}
