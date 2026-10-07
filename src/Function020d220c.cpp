#include "System/Mutex.h"

extern "C" Mutex data_02112754;

extern "C" void func_020d220c()
{
    UnlockMutex(&data_02112754);
}
