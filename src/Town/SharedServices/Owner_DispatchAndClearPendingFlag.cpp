#include <globaldefs.h>
ARM
extern "C" int ItemDetail_DispatchDisplayState(void *);
// Original: arm9/ov003 @ 0x02174988; symbol: func_ov003_02174988; size: 0x38.
extern "C" void Owner_DispatchAndClearPendingFlag(unsigned char *owner) {
    if ((*(unsigned short *)(owner + 0x1046) & 0x80) == 0) return;
    if (ItemDetail_DispatchDisplayState(owner + 0x3c)) {
        unsigned int flags = *(unsigned short *)(owner + 0x1046);
        *(unsigned short *)(owner + 0x1046) = (unsigned short)(flags & ~0x80u);
    }
}
