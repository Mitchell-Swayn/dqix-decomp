#include "System/Mutex.h"
#include "System/RuntimeState.h"
#pragma optimize_for_size off

extern Mutex data_020f3060;
extern "C" void func_0200159c(int);

extern "C" int func_02003ddc(int signal)
{
    if (signal < 1 || signal > 7)
        return -1;
    // Preserve the original return-value test and recursive bookkeeping.
    if (!TryLockMutex(&data_020f3060)) {
        data_020f2f70[7] = data_02111304.activeContext->uniqueID;
        data_020f2f94[7] = 1;
    } else if (data_020f2f70[7] == data_02111304.activeContext->uniqueID) {
        ++data_020f2f94[7];
    } else {
        LockMutex(&data_020f3060);
        data_020f2f70[7] = data_02111304.activeContext->uniqueID;
        data_020f2f94[7] = 1;
    }
    RuntimeSignalHandler handler = data_020f3394[signal - 1];
    if (handler != (RuntimeSignalHandler)1)
        data_020f3394[signal - 1] = 0;
    if (--data_020f2f94[7] == 0)
        UnlockMutex(&data_020f3060);
    if (handler == (RuntimeSignalHandler)1 || (handler == 0 && signal == 1))
        return 0;
    if (handler == 0)
        func_0200159c(0);
    handler(signal);
    return 0;
}

