#include <globaldefs.h>
ARM
extern "C" void* Menu_SelectAlternateCatalogueEntryBySecondaryRank(void*, unsigned, unsigned, unsigned, unsigned);
// Original: arm9/ov023 @ 0x021E1870; symbol: func_ov023_021e1870; size: 0x5C.
extern "C" void Resource_BuildLinkedNodeChainWithExtraArgument(void** head, unsigned a, unsigned b, unsigned c, unsigned extra) {
    void* node = Menu_SelectAlternateCatalogueEntryBySecondaryRank(head, a, b, c, extra);
    if (node == 0) return;
    *head = node;
    while (node != 0) {
        void* next = Menu_SelectAlternateCatalogueEntryBySecondaryRank(head, a, b, c, extra);
        *(void**)node = next;
        node = next;
    }
}
