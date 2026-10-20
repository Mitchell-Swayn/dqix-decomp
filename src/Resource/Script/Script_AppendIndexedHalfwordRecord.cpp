#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108ed8; symbol: data_02108ed8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage[];extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);extern "C" void Object_AllocateTwentyFourByteEntries(unsigned,unsigned,int);
// Original: arm9/main @ 0x0207ED1C; symbol: func_0207ed1c; size: 0x2C.
extern "C" int Script_AppendIndexedHalfwordRecord(void* p){int n=_ZNK6Script9Parameter5ToIntEv(p);Object_AllocateTwentyFourByteEntries(ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage[1],ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage[0],(short)n);return 1;}
