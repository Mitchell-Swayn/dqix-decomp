#include <globaldefs.h>
ARM
extern "C" void* Menu_SelectAlternateCatalogueEntryByPrimaryRank(void*, int, int, int, int);
// Original: arm9/ov023 @ 0x021E1814; symbol: func_ov023_021e1814; size: 0x5C.
extern "C" void Menu_BuildAlternateCatalogueByPrimaryRank(void** head, int a, int b, int c, int d) {
    void* node = Menu_SelectAlternateCatalogueEntryByPrimaryRank(head, a, b, c, d);
    if (!node)
        return;
    *head = node;
    while (node) {
        void* next = Menu_SelectAlternateCatalogueEntryByPrimaryRank(head, a, b, c, d);
        *(void**)node = next;
        node = next;
    }
}
