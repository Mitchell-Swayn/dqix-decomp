#include <globaldefs.h>
ARM
extern "C" char Text_FormatGlobalDataAndSubmitToResource_FormatSPac[],Text_FormatGlobalDataAndSubmitToResource_PathDataPackLv5MinimaptGp2[];extern "C" char* GameResources_GetInstance();extern "C" void WorldMap_ResetDisplayAndMarkerState(void*);extern "C" char* Zone3D_GetMainInstance();extern "C" int sprintf(char*,const char*,...);extern "C" void BackgroundLoader_QueueArchiveFileAndMarkPending(void*,const char*,const char*);
// Original: arm9/main @ 0x020DC3D4; symbol: func_020dc3d4; size: 0x54.
extern "C" void Text_FormatGlobalDataAndSubmitToResource(){char text[24];void* p=*(void**)(GameResources_GetInstance()+0x36d0);WorldMap_ResetDisplayAndMarkerState(p);sprintf(text,Text_FormatGlobalDataAndSubmitToResource_FormatSPac,Zone3D_GetMainInstance()+38);BackgroundLoader_QueueArchiveFileAndMarkPending(p,Text_FormatGlobalDataAndSubmitToResource_PathDataPackLv5MinimaptGp2,text);}
