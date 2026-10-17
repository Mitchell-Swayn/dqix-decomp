#include <globaldefs.h>
#include <System/Mutex.h>
ARM
#pragma optimization_level 4
extern "C" {
    extern Mutex data_02112754;
// Original: arm9/main @ 0x020D21F8; symbol: func_020d21f8; size: 0x14.
    void Object_InvokeLockMutex(){
        LockMutex(&data_02112754);
    }
}
