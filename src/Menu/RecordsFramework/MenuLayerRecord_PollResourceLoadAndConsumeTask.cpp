#include <globaldefs.h>
ARM
extern "C" int MenuRecordList_GetBackgroundTaskId(...);
extern "C" int MenuRecordList_SetBackgroundTaskId(...);
extern "C" int _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" int _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(...);
extern "C" int _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(...);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(...);
extern "C" int Menu_GetDisplayRecordRegistry(...);
extern "C" int Resource_LoadNamedVariableBlocks(...);
extern "C" int MenuLayerRecord_ApplyContainerLayerPayloads(...);
extern "C" int MenuLayerRecord_ApplyResidentOwnerResource(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov023 @ 0x021F7688; symbol: PollAndApplyLoadedResourceTask.
extern "C" int MenuLayerRecord_PollResourceLoadAndConsumeTask(char*self,char*context){
if(!W(self,16)){MenuLayerRecord_ApplyResidentOwnerResource(self,context);return 2;}int taskOwner=Menu_GetDisplayRecordRegistry(context);int loader=_ZN16BackgroundLoader11GetInstanceEv();int task=MenuRecordList_GetBackgroundTaskId(taskOwner);if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)){if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)==2){void*data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&data,&size);if(data&&size){if(B(self,12)&2)MenuLayerRecord_ApplyContainerLayerPayloads(self,context,1,data,size);else Resource_LoadNamedVariableBlocks(self,context,data,size);}}_ZN16BackgroundLoader10RemoveTaskEi(loader,task);MenuRecordList_SetBackgroundTaskId(taskOwner,-1);return 2;}return W(self,28);
}
