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
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Root WMiCheckIdle_UnknownRoleZeroInitializedStorage;
extern "C" int WirelessCommand_ReadInitializedStatus();
// Original: arm9/main @ 0x020D424C; symbol: func_020d424c; size: 0x94.
extern "C" ARM int TestCurrentStatusAgainstVariadicAllowedValues(unsigned count, ...) {
    va_list arguments;
    int result = WirelessCommand_ReadInitializedStatus();
    if (result) return result;
    InvalidateDataCacheRange(WMiCheckIdle_UnknownRoleZeroInitializedStorage.context->status, 2);
    unsigned short* statusPointer = WMiCheckIdle_UnknownRoleZeroInitializedStorage.context->status;
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
