#include <globaldefs.h>
extern "C" unsigned *Menu_SelectCatalogueEntryByPrimaryRank(void *, int, int, int);
// Original: arm9/ov023 @ 0x021E1B0C; symbol: func_ov023_021e1b0c; size: 0x50.
extern "C" void Menu_BuildCatalogueByPrimaryRank(unsigned **head, int a, int b, int c) {
    unsigned *node = Menu_SelectCatalogueEntryByPrimaryRank(head, a, b, c);
    if (!node) return;
    *head = node;
    while (node) {
        unsigned *next = Menu_SelectCatalogueEntryByPrimaryRank(head, a, b, c);
        *node = (unsigned)next;
        node = next;
    }
}
