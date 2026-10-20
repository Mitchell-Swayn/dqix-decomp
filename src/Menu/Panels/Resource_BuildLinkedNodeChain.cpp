#include <globaldefs.h>
ARM
extern "C" void* Menu_SelectCatalogueEntryBySecondaryRank(void*, unsigned, unsigned, unsigned);
// Original: arm9/ov023 @ 0x021E1B5C; symbol: func_ov023_021e1b5c; size: 0x50.
extern "C" void Resource_BuildLinkedNodeChain(void** head, void* a, unsigned b, unsigned c) {
    void* node = Menu_SelectCatalogueEntryBySecondaryRank(head, (unsigned)a, b, c);
    if (node == 0) return;
    *head = node;
    while (node != 0) {
        void* next = Menu_SelectCatalogueEntryBySecondaryRank(head, (unsigned)a, b, c);
        *(void**)node = next;
        node = next;
    }
}
