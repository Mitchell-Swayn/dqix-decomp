#include <globaldefs.h>
ARM
struct State;
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" unsigned MenuRecordList_GetBackgroundTaskId(void*);
extern "C" void MenuRecordList_SetBackgroundTaskId(void*,int);
extern "C" void World_LoadZoneRenderPartWithSavedVram(char*,State*,const void*,int);
// Original: arm9/ov023 @ 0x021F707C; symbol: func_ov023_021f707c; size: 0xAC.
extern "C" int World_PollZoneRenderPartLoad(char* self,State* state) {
 void* data=Menu_GetDisplayRecordRegistry(state);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 unsigned task=MenuRecordList_GetBackgroundTaskId(data);
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)) {
  if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)==2) {
   void* file; unsigned size;
   _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&file,&size);
   World_LoadZoneRenderPartWithSavedVram(self,state,file,size);
  }
  _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
  MenuRecordList_SetBackgroundTaskId(data,-1);
  return 2;
 }
 return *(int*)(self+0x1c);
}
