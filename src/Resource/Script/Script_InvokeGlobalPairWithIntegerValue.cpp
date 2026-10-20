#include <Resource/Script.h>
// Original data: arm9/main @ 0x2108ee0; symbol: data_02108ee0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void DisplayLayout_AllocateParts(void*,void*,short); extern "C" void *DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage[2];
// Original: arm9/main @ 0x0207F12C; symbol: func_0207f12c; size: 0x2C.
 extern "C" int Script_InvokeGlobalPairWithIntegerValue(const Script::Parameter *param) { int signExtended=param->ToInt(); DisplayLayout_AllocateParts(DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage[1],DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage[0],signExtended); return 1; }
