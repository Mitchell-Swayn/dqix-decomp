#include <globaldefs.h>
ARM
extern "C" void *Menu_SelectEnabledCatalogueEntryBySecondaryRank(void *, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov023 @ 0x021E15B4; symbol: func_ov023_021e15b4; size: 0x50.
extern "C" void Menu_BuildEnabledCatalogueBySecondaryRank(void **head, unsigned int a, unsigned int b, unsigned int c) {
    void *node = Menu_SelectEnabledCatalogueEntryBySecondaryRank(head, a, b, c);
    if (node == 0) return;
    *head = node;
    goto check_node;
loop_body:
    {
        void *next = Menu_SelectEnabledCatalogueEntryBySecondaryRank(head, a, b, c);
        *(void **)node = next;
        node = next;
    }
check_node:
    if (node != 0) goto loop_body;
}
