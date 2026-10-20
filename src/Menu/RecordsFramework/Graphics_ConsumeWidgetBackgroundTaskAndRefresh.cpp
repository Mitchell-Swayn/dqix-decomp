#include <globaldefs.h>
ARM
extern "C" char* Menu_GetDisplayRecordRegistry(...);
extern "C" char* _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" int MenuRecordList_GetBackgroundTaskId(...);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(...);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(...);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(...);
extern "C" void MenuLayerRecord_ApplyContainerLayerPayloads(...);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" void MenuRecordList_SetBackgroundTaskId(...);
extern "C" void Graphics_TransferScreenBuffer(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};struct Vec {int x,y,z;};
// Original: arm9/ov023 @ 0x021F78A4; symbol: Graphics_ConsumeWidgetBackgroundTaskAndRefresh; size: 0xe0.
// Consumes completed widget task data, removes task, resets handle and refreshes embedded canvas unless hidden.
extern "C" void Graphics_ConsumeWidgetBackgroundTaskAndRefresh(char* self){if(B(self,12)&2){char* owner=P(self,32);char* handle=Menu_GetDisplayRecordRegistry(owner);char* loader=_ZN16BackgroundLoader11GetInstanceEv();int task=MenuRecordList_GetBackgroundTaskId(handle);if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)){if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)==2){char* data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&data,&size);if(data&&size)MenuLayerRecord_ApplyContainerLayerPayloads(self,owner,0,data,size);}_ZN16BackgroundLoader10RemoveTaskEi(loader,task);MenuRecordList_SetBackgroundTaskId(handle,-1);W(self,28)=2;}}if(!(B(self,12)&1))Graphics_TransferScreenBuffer(self+40,0);}
