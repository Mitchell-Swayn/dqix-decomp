#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" unsigned _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" char* Zone3D_GetMainInstance();
extern "C" void Script_LoadAndExecuteZoneTriggers(void*,void*);
extern "C" char Field_LoadAndExecuteCurrentZoneTriggers_TextScenarioTriggerBin[];
// Original: arm9/ov017 @ 0x021B8C84; symbol: QueueAndCompleteBackgroundReferenceLoad; size: 0x94.
// Queues referenced background file once, applies successful result, removes completed task and marks state byte.
extern "C" void Field_LoadAndExecuteCurrentZoneTriggers(char* p){
 _ZN9GameState11GetInstanceEv();void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 int task=*(int*)(p+8);if(task==-1){*(unsigned*)(p+8)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Field_LoadAndExecuteCurrentZoneTriggers_TextScenarioTriggerBin,0);return;}
 if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,task))return;
 if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,*(unsigned*)(p+8))==2){void* global=GameState_GetSerializedProgressState();Script_LoadAndExecuteZoneTriggers(global,*(void**)(Zone3D_GetMainInstance()+8));}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+8));*(int*)(p+8)=-1;p[1]=1;
}
