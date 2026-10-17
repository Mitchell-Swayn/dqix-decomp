#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020D0840; symbol: func_020d0840; size: 0xC.
    bool Card_IsReadManagerIdle(){
        return IsCardReadManagerIdle();
    }
}
