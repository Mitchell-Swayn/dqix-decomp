#include <globaldefs.h>
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*, void*);
// Original: arm9/ov023 @ 0x021F6630; symbol: func_ov023_021f6630; size: 0x50.
extern "C" ARM void MenuTextCanvas_SetPageIndexAndCountByKey(void* owner, unsigned short id, unsigned short valueA, unsigned short valueB) {
    void** head = (void**)Menu_GetDisplayRecordRegistry(owner);
    void* record = MenuRecordList_LocateByKey(head, id);
    if (!record || MenuRecord_GetType(record) != 6) return;
    *(unsigned short*)((char*)record + 0x104) = valueA;
    *(unsigned short*)((char*)record + 0x106) = valueB;
    MenuTextCanvas_RefreshConfiguredFrameAndContents(record, owner);
}
