#include <globaldefs.h>
ARM
extern "C" int GetInventoryItemByID(char*, int, int);
extern "C" void* ZoneState2754_FindPrimaryRecordByKey(void*, int);
// Original: arm9/ov002 @ 0x02157500; symbol: func_ov002_02157500; size: 0x3C.
extern "C" unsigned GetInventoryRecordSlot(unsigned char* inventory, int index, int category) {
    int id = GetInventoryItemByID((char*)inventory, index, category);
    if (id < 0) return 0;
    void* record = ZoneState2754_FindPrimaryRecordByKey(inventory + 0x7ec, id);
    return record ? (*(unsigned*)((char*)record + 8) << 16) >> 30 : 0;
}
