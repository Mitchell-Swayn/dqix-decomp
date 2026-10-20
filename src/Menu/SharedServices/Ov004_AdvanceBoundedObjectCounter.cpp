#include <globaldefs.h>
extern "C" void* Menu_FindInventoryGridByKey(void*, unsigned);
extern "C" void Menu_RefreshSixOfferRows(void*);
// Original: arm9/ov004 @ 0x0215CDAC; symbol: func_ov004_0215cdac; size: 0x44.
extern "C" ARM int Ov004_AdvanceBoundedObjectCounter(void* object) {
    void* record = Menu_FindInventoryGridByKey(object, 0x5b);
    short current = *(short*)((char*)record + 0x5c);
    short limit = *(short*)((char*)record + 0x5e);
    short next = current + 1;
    if (limit <= next) next = 0;
    *(short*)((char*)record + 0x5c) = next;
    *(short*)((char*)record + 0x5e) = limit;
    Menu_RefreshSixOfferRows(object);
    return 0;
}
