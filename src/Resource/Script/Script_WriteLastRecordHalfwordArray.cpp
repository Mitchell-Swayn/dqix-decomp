#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x2108ed8; symbol: data_02108ed8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* DisplayLayout_GetGroupByIndex(void*,int);extern "C" void* ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage[2];
// Original: arm9/main @ 0x0207EEF8; symbol: func_0207eef8; size: 0x68.
extern "C" int Script_WriteLastRecordHalfwordArray(Script::Parameter* p){void* table=ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage[1];unsigned char* entry=DisplayLayout_GetGroupByIndex(table,(short)(*(short*)((unsigned char*)table+4)-1));unsigned short* values=*(unsigned short**)(entry+4);for(unsigned char i=0;i<entry[20];i++)values[i]=(p++)->ToInt();return 1;}
