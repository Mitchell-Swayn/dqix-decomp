#include <globaldefs.h>
ARM
extern "C" void *Menu_FindInventoryGridByKey(void *, unsigned int);
extern "C" void Menu_RefreshListingInventoryPage(void *);
// Original: arm9/ov004 @ 0x0215CE7C; symbol: func_ov004_0215ce7c; size: 0x48.
extern "C" int Menu_ShowPreviousInventoryItemPage(void *owner) {
    void *object = Menu_FindInventoryGridByKey(owner, 0x63);
    short next = *(short *)((char *)object + 0x5c) - 1;
    short limit = *(short *)((char *)object + 0x5e);
    if (next < 0) next = limit - 1;
    *(short *)((char *)object + 0x5c) = next;
    *(short *)((char *)object + 0x5e) = limit;
    Menu_RefreshListingInventoryPage(owner);
    return 0;
}
