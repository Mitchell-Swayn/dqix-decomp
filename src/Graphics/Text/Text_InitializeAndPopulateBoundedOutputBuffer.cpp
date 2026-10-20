#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f2a24; symbol: data_020f2a24.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 922a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2a3c; symbol: data_020f2a3c.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 1c2b0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern int TextInitializeAndPopulateBoundedOutputBuffer_UnknownRoleDataReferences_Variant2;extern int TextInitializeAndPopulateBoundedOutputBuffer_UnknownRoleDataReferences;void ResourceStringLoader_Initialize(void*);void ResourceStringLoader_Reset(void*);void LoadAndProcessDataWithOptionalBackgroundLoaderLock(char*,int,int,int,int,int);
// Original: arm9/main @ 0x020DCFC8; symbol: func_020dcfc8; size: 0x78.
void Text_InitializeAndPopulateBoundedOutputBuffer(int size,char* out){if(size>0&&out){*out=0;int b;int a=TextInitializeAndPopulateBoundedOutputBuffer_UnknownRoleDataReferences_Variant2;b=TextInitializeAndPopulateBoundedOutputBuffer_UnknownRoleDataReferences;unsigned char state[24];ResourceStringLoader_Initialize(state);ResourceStringLoader_Reset(state);LoadAndProcessDataWithOptionalBackgroundLoaderLock(out,b,size,0,1,a);}}}
