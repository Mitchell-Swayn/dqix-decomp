#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109ba8; symbol: data_02109ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage;extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);extern "C" void SpellTable_AppendVocationLearningEntry(void*,int,void*);
// Original: arm9/main @ 0x0209A7BC; symbol: func_0209a7bc; size: 0x48.
extern "C" int Script_WriteHalfwordPairForIntegerKey(char* p){int n=_ZNK6Script9Parameter5ToIntEv(p);unsigned short pair[2];pair[0]=_ZNK6Script9Parameter5ToIntEv(p+8);pair[1]=_ZNK6Script9Parameter5ToIntEv(p+16);SpellTable_AppendVocationLearningEntry(ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage,n,pair);return 1;}
