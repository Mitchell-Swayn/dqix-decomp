#include <globaldefs.h>
ARM
extern "C" void* Menu_SelectEnabledCatalogueEntryByPrimaryRank(void*, int, int, int);
// Original: arm9/ov023 @ 0x021E1564; symbol: Unclassified_BuildLinkedListFromNodeFactory; size: 0x50.
// Calls the node factory with the caller arguments, stores its first result as the head, and links further nodes until the factory returns null.
extern "C" void Menu_BuildEnabledCatalogueByPrimaryRank(void** head, int a, int b, int c) {
    void* node = Menu_SelectEnabledCatalogueEntryByPrimaryRank(head, a, b, c);
    if (!node) return;
    *head = node;
    while (node) {
        void* next = Menu_SelectEnabledCatalogueEntryByPrimaryRank(head, a, b, c);
        *(void**)node = next;
        node = next;
    }
}
