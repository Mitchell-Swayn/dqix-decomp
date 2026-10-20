#include <globaldefs.h>
ARM
extern "C" unsigned short TileGrid_GetSelectedCellHandleByKey(void *object);
extern "C" void *Menu_GetDisplayRecordRegistry(void *self);
extern "C" void *MenuRecordList_LocateByKey(void **head, unsigned short value);
// Original: arm9/ov023 @ 0x021F6590; symbol: func_ov023_021f6590; size: 0x24.
extern "C" void TileGrid_FindSelectedChildRecord(void *object) {
    unsigned short value = TileGrid_GetSelectedCellHandleByKey(object);
    void *head = Menu_GetDisplayRecordRegistry(object);
    MenuRecordList_LocateByKey((void **)head, value);
}
