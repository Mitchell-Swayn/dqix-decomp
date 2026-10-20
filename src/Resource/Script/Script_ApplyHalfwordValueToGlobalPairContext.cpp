#include <globaldefs.h>
ARM
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2109fe0; symbol: data_02109fe0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage[]; extern "C" void Object_Allocate44ByteArrayForPositiveCount(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020A7F5C; symbol: func_020a7f5c; size: 0x2C.
 extern "C" int Script_ApplyHalfwordValueToGlobalPairContext(Script::Parameter* p) { unsigned value=p->ToInt(); Object_Allocate44ByteArrayForPositiveCount(ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage[1],ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage[0],(unsigned short)value); return 1; }
