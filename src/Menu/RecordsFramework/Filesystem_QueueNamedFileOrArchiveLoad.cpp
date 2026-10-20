#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct State;
extern "C" char Filesystem_QueueNamedFileOrArchiveLoad_PathDataS[];
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" int MenuRecordList_GetBackgroundTaskId(void*);
extern "C" void MenuRecordList_SetBackgroundTaskId(void*,int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
// Original: arm9/ov023 @ 0x021F75D0; symbol: func_ov023_021f75d0; size: 0xB8.
extern "C" int Filesystem_QueueNamedFileOrArchiveLoad(unsigned char* self,State* state) {
 void* data=Menu_GetDisplayRecordRegistry(state);
 if(!*(const char**)(self+0x10)) return 1;
 if(MenuRecordList_GetBackgroundTaskId(data)<0) {
  void* loader=_ZN16BackgroundLoader11GetInstanceEv();
  char path[80];
  if(*(const char**)(self+0x24)) sprintf(path,Filesystem_QueueNamedFileOrArchiveLoad_PathDataS,*(const char**)(self+0x24));
  else sprintf(path,Filesystem_QueueNamedFileOrArchiveLoad_PathDataS,*(const char**)(self+0x10));
  int task;
  if(*(const char**)(self+0x24)) task=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,path,*(const char**)(self+0x10),0);
  else task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
  MenuRecordList_SetBackgroundTaskId(data,task);
  return 1;
 }
 return *(int*)(self+0x1c);
}
