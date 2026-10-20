#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" int MenuRecordList_GetBackgroundTaskId(void *);
extern "C" void MenuRecordList_SetBackgroundTaskId(void *, unsigned int);
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" unsigned int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void *, const char *, void *);
extern "C" char MenuModel_QueueResourceLoadWhenIdle_PathDataS[];
// Original: arm9/ov023 @ 0x021FCEB8; symbol: func_ov023_021fceb8; size: 0x6C.
extern "C" int MenuModel_QueueResourceLoadWhenIdle(void *owner, void *asset) {
    void *loaderState = Menu_GetDisplayRecordRegistry(asset);
    int status = MenuRecordList_GetBackgroundTaskId(loaderState);
    if (status >= 0) return *(int *)((char *)owner + 0x1c);
    char path[0x50];
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    sprintf(path, MenuModel_QueueResourceLoadWhenIdle_PathDataS, *(unsigned int *)((char *)owner + 0x10));
    unsigned int queued = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, path, 0);
    MenuRecordList_SetBackgroundTaskId(loaderState, queued);
    return 1;
}
