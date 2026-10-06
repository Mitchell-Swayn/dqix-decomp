#include "System/Mutex.h"

// The original thunk passes the mutex stored at 0x02112754 to LockMutex.
extern "C" Mutex data_02112754;

extern "C" void func_020d21f8()
{
    LockMutex(&data_02112754);
}
