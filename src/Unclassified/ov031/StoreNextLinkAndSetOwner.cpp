#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022070E0; symbol: func_ov031_022070e0; size: 0x10.
extern "C" void StoreNextLinkAndSetOwner(void *node, void *owner) {
    *(void **)((char *)owner + 0x7c) = *(void **)node;
    *(void **)node = owner;
}
