#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" int MenuRecordList_GetBackgroundTaskId(void*);
extern "C" void MenuRecordList_SetBackgroundTaskId(void*, unsigned int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void* _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*, const char*, const char*, void*);
extern "C" char Filesystem_QueueBackgroundLoadWhenStatusNegative_PathDataPrmItemsortGp2;
extern "C" char Filesystem_QueueBackgroundLoadWhenStatusNegative_MarkupItemsortLGBin;
// Original: arm9/ov023 @ 0x021FC2B8; symbol: func_ov023_021fc2b8; size: 0x54.
extern "C" void* Filesystem_QueueBackgroundLoadWhenStatusNegative(void* owner, void* state) {
    void* entry = Menu_GetDisplayRecordRegistry(state);
    int status = MenuRecordList_GetBackgroundTaskId(entry);
    if (status >= 0) return *(void**)((char*)owner + 0x1c);
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    void* task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
        loader, &Filesystem_QueueBackgroundLoadWhenStatusNegative_PathDataPrmItemsortGp2, &Filesystem_QueueBackgroundLoadWhenStatusNegative_MarkupItemsortLGBin, 0);
    MenuRecordList_SetBackgroundTaskId(entry, (unsigned int)task);
    return (void*)1;
}
