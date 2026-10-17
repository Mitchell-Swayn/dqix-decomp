#include <globaldefs.h>
#pragma optimization_level 2
#pragma optimize_for_size off
#pragma opt_propagation off

typedef char* va_list;
#define va_start(ap,last) ((ap)=(char*)(((unsigned)&last & ~3U)+4))
#define va_arg(ap,type) (*(type*)(((ap)+=sizeof(type))-sizeof(type)))
#define va_end(ap) ((void)0)
#include <System/Cache.h>
struct Context { int unknown; unsigned short* status; };
struct Root { unsigned short active, pad; Context* context; };
extern "C" Root data_021142e0;
extern "C" int WirelessCommand_ReadInitializedStatus();
// Original: arm9/main @ 0x020D424C; symbol: func_020d424c; size: 0x94.
extern "C" ARM int TestCurrentStatusAgainstVariadicAllowedValues(unsigned count, ...) {
    va_list arguments;
    int result = WirelessCommand_ReadInitializedStatus();
    if (result) return result;
    InvalidateDataCacheRange(data_021142e0.context->status, 2);
    unsigned short* statusPointer = data_021142e0.context->status;
    va_start(arguments, count);
    unsigned status = *statusPointer;
    result = 3;
    if (!count) return result;
    do {
        if (va_arg(arguments, unsigned) == status) result = 0;
    } while (--count);
    va_end(arguments);
    return result;
}
