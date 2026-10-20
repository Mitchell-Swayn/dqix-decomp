#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
// Original: arm9/ov004 @ 0x0216AE9C; symbol: Resource_FindTypeSixEntryByKey; size: 0x34.
// Finds the keyed entry and returns it only when its embedded halfword type equals 6.
extern "C" void* Menu_FindTextCanvasWidgetByKey(void* self, unsigned short key) {
    void* head = Menu_GetDisplayRecordRegistry(self);
    void* node = MenuRecordList_LocateByKey((void**)head, key);
    if (!node) return 0;
    if (MenuRecord_GetType(node) != 6) node = 0;
    return node;
}
