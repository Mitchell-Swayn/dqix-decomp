#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/main @ 0x2111800; symbol: data_02111800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* InvokeGlobalTailListHandler_UnknownRoleZeroInitializedStorage;extern "C" void PowerManagement_AppendCallback(void**,void*);
// Original: arm9/main @ 0x020CEF4C; symbol: func_020cef4c; size: 0x18.
extern "C" void LinkedList_AppendEntryToGlobalPendingList(void* entry){PowerManagement_AppendCallback(&InvokeGlobalTailListHandler_UnknownRoleZeroInitializedStorage,entry);}
