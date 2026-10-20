#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20f0d2c; symbol: data_020f0d2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffff.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108dd8; symbol: data_02108dd8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern int ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleInitializedBytes;extern unsigned short *ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleZeroInitializedStorage;}
// Original: arm9/main @ 0x02074060; symbol: func_02074060; size: 0xB4.
extern "C" ARM int Script_SetMatchingIdAndEightGlobalHalfwords(Script::Parameter *p){int i;int id=(p++)->ToInt();if(id!=ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleInitializedBytes)return 1;ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleZeroInitializedStorage[0]=(unsigned short)id;for(i=0;i<3;i++){(ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleZeroInitializedStorage+i)[1]=(unsigned short)p->ToInt();Script::Parameter*r=p+1;p+=2;(ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleZeroInitializedStorage+i)[4]=(unsigned short)r->ToInt();}ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleZeroInitializedStorage[7]=(unsigned short)p->ToInt();ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleZeroInitializedStorage[8]=(unsigned short)(p+1)->ToInt();ScriptSetMatchingIdAndEightGlobalHalfwords_UnknownRoleZeroInitializedStorage[9]=0;return 1;}
