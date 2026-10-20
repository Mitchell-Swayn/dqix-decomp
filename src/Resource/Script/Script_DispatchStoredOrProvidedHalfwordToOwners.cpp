#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x2108db0; symbol: data_02108db0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage[];extern "C" void Object_AllocateEightByteIdValueEntries(void*,void*,unsigned);
// Original: arm9/main @ 0x02072628; symbol: func_02072628; size: 0x54.
extern "C" int Script_DispatchStoredOrProvidedHalfwordToOwners(Script::Parameter* p){unsigned n=(unsigned short)p->ToInt();if(*(void**)(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage+4))return 1;if(*(void**)(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage+8)&&*(unsigned short*)(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage+2))n=*(unsigned short*)(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage+2);Object_AllocateEightByteIdValueEntries(*(void**)(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage+16),*(void**)(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage+12),n);return 1;}
