#include <globaldefs.h>
extern "C" int sprintf(char*, const char*, ...);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" int MenuRecordList_GetBackgroundTaskId(void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*, const char*, void*);
extern "C" void MenuRecordList_SetBackgroundTaskId(void*, unsigned);
extern "C" char Ov023_LoadAssetForNegativeField_PathDataS[];
// Original: arm9/ov023 @ 0x021F7010; symbol: func_ov023_021f7010; size: 0x6C.
extern "C" ARM void* Ov023_LoadAssetForNegativeField(void* object, void* context) {
    void* record = Menu_GetDisplayRecordRegistry(context);
    if (MenuRecordList_GetBackgroundTaskId(record) >= 0)
        return *(void**)((char*)object + 0x1c);
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    char path[0x50];
    sprintf(path, Ov023_LoadAssetForNegativeField_PathDataS, *(char**)((char*)object + 0x10));
    unsigned handle = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, path, 0);
    MenuRecordList_SetBackgroundTaskId(record, handle);
    return (void*)1;
}
