#pragma optimize_for_size off
#pragma opt_common_subs off
#include <globaldefs.h>
struct StartupState { unsigned int previous; unsigned int reserved; unsigned int flag; };
// Original data: arm9/main @ 0x2111588; symbol: data_02111588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" StartupState SystemInvokeExceptionCallback_UnknownRoleZeroInitializedStorage;
extern "C" void System_HandleProcessorException();
struct BootArea { char pad[0xfdc]; unsigned int entry; };
// Original: arm9/main @ 0x020C8A3C; symbol: func_020c8a3c; size: 0x70.
extern "C" void System_InitializeExceptionHandler() {
    unsigned int* slot = (unsigned int*)0x027ffd9c;
    BootArea* area = (BootArea*)0x027e3000;
    unsigned int value = *slot;
    if (value >= 0x02600000 && value < 0x02800000) SystemInvokeExceptionCallback_UnknownRoleZeroInitializedStorage.previous = value;
    else SystemInvokeExceptionCallback_UnknownRoleZeroInitializedStorage.previous = 0;
    if (!SystemInvokeExceptionCallback_UnknownRoleZeroInitializedStorage.previous) {
        *slot = (unsigned int)&System_HandleProcessorException;
        area->entry = (unsigned int)&System_HandleProcessorException;
    }
    SystemInvokeExceptionCallback_UnknownRoleZeroInitializedStorage.flag = 0;
}
