#include "System/IPC.h"

extern "C" void func_020d2880()
{
    while (SendCommandToArm7(7, 0, false) < IPCResult_Success)
    {
    }
}
