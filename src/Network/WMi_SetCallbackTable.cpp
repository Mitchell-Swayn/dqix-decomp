#include <globaldefs.h>
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern unsigned int *WMiCheckIdle_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D404C; symbol: func_020d404c; size: 0x18.
void WMi_SetCallbackTable(int i,unsigned int v){unsigned int *p=WMiCheckIdle_UnknownRoleZeroInitializedStorage[1];*(unsigned int *)((char *)(p+i)+0x18)=v;} }
