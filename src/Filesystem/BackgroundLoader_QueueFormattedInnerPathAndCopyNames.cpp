#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20ef460; symbol: data_020ef460.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 70f40e0281f40e02b0f40e02caf40e02.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" unsigned char* Zone3D_GetMainInstance();extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);extern "C" int sprintf(char*,const char*,...);extern "C" char* strcpy(char*,const char*);extern "C" char BackgroundLoader_QueueFormattedInnerPathAndCopyNames_FormatSBmmp[];extern "C" char* WorldMapAdvanceZoneMapLoad_UnknownRoleDataReferences[3];extern "C" char BackgroundLoader_QueueFormattedInnerPathAndCopyNames_TextT99MAP01[];
// Original: arm9/main @ 0x02020B98; symbol: func_02020b98; size: 0x80.
extern "C" int BackgroundLoader_QueueFormattedInnerPathAndCopyNames(unsigned char* p){void* loader=_ZN16BackgroundLoader11GetInstanceEv();unsigned char* ctx=Zone3D_GetMainInstance();char path[32];sprintf(path,BackgroundLoader_QueueFormattedInnerPathAndCopyNames_FormatSBmmp,ctx+38);int task=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,WorldMapAdvanceZoneMapLoad_UnknownRoleDataReferences[2],path,0);strcpy((char*)p+0xa35,(char*)ctx+38);strcpy((char*)p+0x548,BackgroundLoader_QueueFormattedInnerPathAndCopyNames_TextT99MAP01);return task;}
