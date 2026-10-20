#include <globaldefs.h>
ARM
struct State;
extern "C" {void* _ZN16BackgroundLoader11GetInstanceEv();unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);unsigned _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void* Menu_GetDisplayRecordRegistry(State*);void MenuRecordList_SetBackgroundTaskId(void*,int);int MenuRecordList_GetBackgroundTaskId(void*);void Graphics_LoadEmbeddedCHRObjectWithAllocators(void*,State*,void*,unsigned);}
// Original: arm9/ov023 @ 0x021FCF24; symbol: func_ov023_021fcf24; size: 0xAC.
extern "C" int PollLoadedFileAndAdvanceRecordState(char* p,State* owner){
void* record=Menu_GetDisplayRecordRegistry(owner);void* loader=_ZN16BackgroundLoader11GetInstanceEv();int task=MenuRecordList_GetBackgroundTaskId(record);
if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)){
if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)==2){void* data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&data,&size);Graphics_LoadEmbeddedCHRObjectWithAllocators(p,owner,data,size);}
_ZN16BackgroundLoader10RemoveTaskEi(loader,task);MenuRecordList_SetBackgroundTaskId(record,-1);return 2;
}
return *(int*)(p+0x1c);
}
