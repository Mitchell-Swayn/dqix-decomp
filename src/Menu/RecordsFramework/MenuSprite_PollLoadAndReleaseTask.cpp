#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* Menu_GetDisplayRecordRegistry(void*);extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" int MenuRecordList_GetBackgroundTaskId(void*);extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,int);extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);extern "C" void MenuSprite_AllocateTileRangeAndLoadAnimation(char*,void*,void*,unsigned);extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);extern "C" void MenuRecordList_SetBackgroundTaskId(void*,int);
// Original: arm9/ov023 @ 0x021FB76C; symbol: PollResourceLoadAndFinalizeTask; size: 0xac.
extern "C" int MenuSprite_PollLoadAndReleaseTask(char* self,void* owner){
void* record=Menu_GetDisplayRecordRegistry(owner);void* loader=_ZN16BackgroundLoader11GetInstanceEv();int id=MenuRecordList_GetBackgroundTaskId(record);if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,id)){if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,id)==2){void* buffer;unsigned length;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,id,&buffer,&length);MenuSprite_AllocateTileRangeAndLoadAnimation(self,owner,buffer,length);}_ZN16BackgroundLoader10RemoveTaskEi(loader,id);MenuRecordList_SetBackgroundTaskId(record,-1);return 2;}return W(self,28);
}
