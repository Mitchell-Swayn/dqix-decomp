#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
ARM
struct State;
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" unsigned MenuRecordList_GetBackgroundTaskId(void*);
extern "C" void MenuRecordList_SetBackgroundTaskId(void*,unsigned);


extern "C" const char QueueDescriptorResourcePathWhenTaskMissing_PathDataS[];
// Original: arm9/ov023 @ 0x021FB700; symbol: func_ov023_021fb700; size: 0x6C.
// Queues the descriptor's formatted resource path when its task handle is negative; otherwise returns the stored result.
extern "C" int QueueDescriptorResourcePathWhenTaskMissing(char* self,State* state){
 char path[80];void* list=Menu_GetDisplayRecordRegistry(state);
 int currentTask=MenuRecordList_GetBackgroundTaskId(list);
 if(currentTask>=0)return *(int*)(self+0x1c);
 BackgroundLoader* loader=BackgroundLoader::GetInstance();
 sprintf(path,QueueDescriptorResourcePathWhenTaskMissing_PathDataS,*(unsigned*)(self+0x10));
 int task=loader->QueueLoadFile(path,0);
 MenuRecordList_SetBackgroundTaskId(list,task);return 1;
}
