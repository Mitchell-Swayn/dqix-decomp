#include <globaldefs.h>
#pragma optimize_for_size off
#include <System/Cache.h>
struct Context { unsigned unknown; unsigned char* data; };
extern "C" Context* WMi_GetSystemWork();
extern "C" int WirelessCommand_ReadInitializedStatus();
// Original: arm9/main @ 0x020D4AC8; symbol: func_020d4ac8; size: 0x90.
extern "C" ARM unsigned short ReadSharedRecordSizeForAllowedTypes() {
    Context* context = WMi_GetSystemWork();
    if (WirelessCommand_ReadInitializedStatus()) return 0;
    InvalidateDataCacheRange(context->data, 2);
    unsigned short type = *(unsigned short*)context->data;
    switch (type) {
    case 9: {
        InvalidateDataCacheRange(context->data + 0x182, 2);
        if (!*(unsigned short*)(context->data + 0x182)) return 0;
    }
    case 10: case 11:
    InvalidateDataCacheRange(context->data + 0xbc, 2);
    return *(unsigned short*)(context->data + 0xbc);
    default: return 0;
    }
}
