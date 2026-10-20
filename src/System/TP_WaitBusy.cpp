#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern volatile unsigned short TPWaitBusy_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020CE0FC; symbol: func_020ce0fc; size: 0x18.
void TP_WaitBusy(unsigned int mask){do{}while(TPWaitBusy_UnknownRoleZeroInitializedStorage[0x1d]&mask);}
}
