#include <globaldefs.h>
#include "System/Cache.h"

extern "C" void* ReadGlobalOperationContextPointerAt4();
extern "C" int WirelessCommand_ReadInitializedStatus();
extern "C" void MIi_CpuCopyFast(const void* source, void* destination, unsigned int size);

// Original: arm9/main @ 0x020D4848; symbol: func_020d4848; size: 0x4C.
extern "C" int WirelessCommand_CopyValidatedSharedTwoThousandByteBlock(int enabled)
{
    unsigned char* root = static_cast<unsigned char*>(ReadGlobalOperationContextPointerAt4());
    int status = WirelessCommand_ReadInitializedStatus();
    if (status != 0) {
        return status;
    }
    if (enabled == 0) {
        return 6;
    }
    InvalidateDataCacheRange(*reinterpret_cast<void**>(root + 4), 2000);
    MIi_CpuCopyFast(*reinterpret_cast<void**>(root + 4), reinterpret_cast<void*>(enabled), 2000);
    return 0;
}
