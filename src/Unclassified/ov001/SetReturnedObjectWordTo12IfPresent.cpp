#include <globaldefs.h>
ARM
extern "C" unsigned int *Pool_AllocateAndLinkNode(void);
// Original: arm9/ov001 @ 0x0215A5D8; symbol: func_ov001_0215a5d8; size: 0x18.
extern "C" unsigned int *SetReturnedObjectWordTo12IfPresent(void) {
    unsigned int *object = Pool_AllocateAndLinkNode();
    if (object)
        *object = 12;
    return object;
}
