#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int MenuRecordList_GetBackgroundTaskId(void*);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(void*,int);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void Script_InstallValidatedPackedTableOrExecuteCharacterVariant(void*,void*,void*,unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void MenuRecordList_SetBackgroundTaskId(void*,int);
// Original: arm9/ov023 @ 0x021FA4C8; symbol: Resource_ConsumeCompletedTaskAndInstallLoadedData; size: 0xb8.
extern "C" int Menu_PollAndConsumeMessageTableLoad(char* self,void* owner) {
 void* record=Menu_GetDisplayRecordRegistry(owner);void* loader=_ZN16BackgroundLoader11GetInstanceEv();int task=MenuRecordList_GetBackgroundTaskId(record);if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)){
 if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)==2){void* file;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&file,&size);if(file && size)Script_InstallValidatedPackedTableOrExecuteCharacterVariant(self,owner,file,size);}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task);MenuRecordList_SetBackgroundTaskId(record,-1);return 2;
 }return *(int*)(self+28);
}
