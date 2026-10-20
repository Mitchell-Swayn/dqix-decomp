#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct State;
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" void* Menu_GetDisplayRecordRegistry(State* self);
extern "C" void MenuRecordList_SetBackgroundTaskId(void*, unsigned);
extern "C" int MenuRecordList_GetBackgroundTaskId(void*);
extern "C" char Filesystem_QueuePendingFileOrArchiveLoad_PathDataS[];
// Original: arm9/ov023 @ 0x021FA8FC; symbol: func_ov023_021fa8fc; size: 0xA8.
extern "C" int Filesystem_QueuePendingFileOrArchiveLoad(char *self, State *state) {
    void *entry = Menu_GetDisplayRecordRegistry(state);
    if (MenuRecordList_GetBackgroundTaskId(entry) < 0) {
        void *loader = _ZN16BackgroundLoader11GetInstanceEv();
        char path[80];
        if (*(char **)(self + 0x20)) sprintf(path, Filesystem_QueuePendingFileOrArchiveLoad_PathDataS, *(char **)(self + 0x20));
        else sprintf(path, Filesystem_QueuePendingFileOrArchiveLoad_PathDataS, *(char **)(self + 0x10));
        unsigned task;
        if (*(char **)(self + 0x20)) task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,path,*(char **)(self + 0x10),0);
        else task = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
        MenuRecordList_SetBackgroundTaskId(entry, task);
        return 1;
    }
    return *(int *)(self + 0x1c);
}
