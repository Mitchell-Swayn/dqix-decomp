#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
#include <std_library_functions.h>
// Original data: arm9/main @ 0x20f2dc8; symbol: data_020f2dc8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 257300.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2dcf; symbol: data_020f2dcf.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2000000000.
// Observed span: 5 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextAppendPrefixAndNameWithSpacing_UnknownRoleInitializedBytes[],Text_AppendPrefixAndNameWithSpacing_Markup1[],TextAppendPrefixAndNameWithSpacing_UnknownRoleInitializedBytes_Variant2[];extern "C" int String_CountBytesUntilTerminator(const char*);extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
// Original: arm9/main @ 0x020E462C; symbol: func_020e462c; size: 0x98.
extern "C" ARM char* Text_AppendPrefixAndNameWithSpacing(char* out,const char* directory,const char* file){if(directory && *directory){out+=sprintf(out,TextAppendPrefixAndNameWithSpacing_UnknownRoleInitializedBytes,directory);int size;int result;if(directory && (size=String_CountBytesUntilTerminator(directory))>3)result=RuntimeMemory_CompareByteRanges(directory+(size-3),Text_AppendPrefixAndNameWithSpacing_Markup1,3);else result=1;if(result)out+=sprintf(out,TextAppendPrefixAndNameWithSpacing_UnknownRoleInitializedBytes_Variant2);}return out+sprintf(out,file);}
