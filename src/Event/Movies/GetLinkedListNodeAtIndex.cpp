#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218E14C; symbol: GetLinkedListNodeAtIndex; size: 0x28.
// Starts at *head and follows +0x18 links count times, returning null if traversal requires a link from null.
extern "C" void *GetLinkedListNodeAtIndex(void *object, int count) {
    void *p = *(void **)object;
    while (count > 0) {
        if (!p)
            return 0;
        p = *(void **)((char *)p + 0x18);
        --count;
    }
    return p;
}
