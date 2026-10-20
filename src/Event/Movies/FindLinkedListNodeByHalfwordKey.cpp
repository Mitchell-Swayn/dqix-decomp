#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218E124; symbol: FindLinkedListNodeByHalfwordKey; size: 0x28.
// Searches the list from *head for a node whose first halfword equals key; next links are at +0x18.
extern "C" void *FindLinkedListNodeByHalfwordKey(void **head, unsigned short key) {
    void *node = *head;
    while (node) {
        if (*(unsigned short *)node == key) return node;
        node = *(void **)((unsigned char *)node + 0x18);
    }
    return 0;
}
