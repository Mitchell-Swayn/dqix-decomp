#include "System/Mutex.h"
#include "System/RuntimeStream.h"
#pragma optimize_for_size off
#pragma dont_inline on

typedef void (*RuntimeExitHandler)();
struct RuntimeExitState {
    RuntimeExitHandler lateHandler;
    RuntimeExitHandler earlyHandler;
    // Reload the shared callback stack count at each original access.
    volatile int handlerCount;
    int aborting;
};
extern RuntimeExitState data_020f2e60;
// Keep the handler fetch before publishing the decremented callback count.
extern RuntimeExitHandler volatile data_020f2e70[];
extern Mutex data_020f2fb8;
extern unsigned int data_020f2f70[];
extern unsigned int data_020f2f94[];
extern "C" int func_02003ddc(int);
extern "C" void func_0200edf4();
extern "C" void func_0200f368();
extern "C" void func_0200159c(int);
extern "C" void func_020015e8(int);

extern "C" void func_02001578()
{
    func_02003ddc(1);
    data_020f2e60.aborting = 1;
    func_0200159c(1);
}
extern "C" void func_0200159c(int status)
{
    if (!data_020f2e60.aborting) {
        func_0200edf4();
        if (data_020f2e60.earlyHandler) {
            data_020f2e60.earlyHandler();
            data_020f2e60.earlyHandler = 0;
        }
    }
    func_020015e8(status);
}
extern "C" void func_020015e8(int)
{
    // Preserve the runtime's observed recursive-lock return-value test.
    if (!TryLockMutex(&data_020f2fb8)) {
        data_020f2f70[0] = data_02111304.activeContext->uniqueID;
        data_020f2f94[0] = 1;
    } else if (data_020f2f70[0] == data_02111304.activeContext->uniqueID) {
        ++data_020f2f94[0];
    } else {
        LockMutex(&data_020f2fb8);
        data_020f2f70[0] = data_02111304.activeContext->uniqueID;
        data_020f2f94[0] = 1;
    }
    if (data_020f2e60.handlerCount > 0) {
        do {
            int index = data_020f2e60.handlerCount - 1;
            RuntimeExitHandler handler = data_020f2e70[index];
            data_020f2e60.handlerCount = index;
            handler();
        } while (data_020f2e60.handlerCount > 0);
    }
    if (--data_020f2f94[0] == 0)
        UnlockMutex(&data_020f2fb8);
    if (data_020f2e60.lateHandler) {
        data_020f2e60.lateHandler();
        data_020f2e60.lateHandler = 0;
    }
    func_02001878(0);
    func_0200f368();
}


