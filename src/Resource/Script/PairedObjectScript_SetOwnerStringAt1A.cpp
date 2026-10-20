#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" char* strcpy(char*,const char*);
// Original data: arm9/main @ 0x2108740; symbol: data_02108740.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);extern "C" char* ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[2];
// Original: arm9/main @ 0x0205E084; symbol: func_0205e084; size: 0x2C.
extern "C" int PairedObjectScript_SetOwnerStringAt1A(const void* p){const char* s=_ZNK6Script9Parameter8ToStringEv(p);if(s)strcpy(ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[1]+26,s);return 1;}
