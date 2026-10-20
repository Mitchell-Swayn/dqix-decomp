#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220D8F4; symbol: func_ov031_0220d8f4; size: 0x90.
extern "C" unsigned short Util_FindNextEnabledBitModuloThirteen(int start){
 int i;
 unsigned flags=*(unsigned*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2264);
 int value=start;
 for(i=0;i<13;i++,value++){
 if(flags&(1<<(value%13+1)))break;
 }
 return (start+i)%13+1;
}
