#include <globaldefs.h>
ARM
extern "C" int ScriptRecordList_InitializeEmpty(...);
extern "C" int Script_CopySelectedIds(...);
extern "C" int Network_GetConnectionManager(...);
extern "C" int Script_ExecuteWithFourGlobalParameters(...);
extern "C" int _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" int _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(...);
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(...);
extern "C" int _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(...);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int __clear(...);
extern "C" int ZoneEncounterLoader_FinalizeNavigationAndEncounterData(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
extern "C" char ZoneEncounterLoader_LoadFieldParametersAndQueueOverrides_PathDataPrmMonModdataNat[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021B5348; symbol: ExecuteLoadedScriptAndQueueFollowupWhenRequested.
extern "C" void ZoneEncounterLoader_LoadFieldParametersAndQueueOverrides(char*self){
_ZN9GameState11GetInstanceEv();char*owner;int loader=_ZN16BackgroundLoader11GetInstanceEv();Network_GetConnectionManager();if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,12)))return;owner=P(self,8);if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,W(self,12))==2){unsigned size;void*data;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,12),&data,&size);if(data){char*current=P(self,8);unsigned short values[12];__clear(values,24);short count=Script_CopySelectedIds(current+68,values);ScriptRecordList_InitializeEmpty(owner+772);Script_ExecuteWithFourGlobalParameters(owner+772,W(P(self,8),16),data,(short)size,values,count);}}_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,12));W(self,12)=-1;if((int)B(owner,776)>0){W(self,12)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,ZoneEncounterLoader_LoadFieldParametersAndQueueOverrides_PathDataPrmMonModdataNat,0);B(self,16)=8;}else ZoneEncounterLoader_FinalizeNavigationAndEncounterData(self);
}
