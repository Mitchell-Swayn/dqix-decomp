#include <globaldefs.h>
extern "C" unsigned ReadCountByteWhenBothOwnerPointersSet(char *);
extern "C" void Object_ResetSelectionAndApplyConfiguredMode(void *, int);
extern "C" void Object_ResetAndDeactivateState(void *);
extern "C" void InitializeRecordGridAndFlagDefaults(void *);
// Original: arm9/ov023 @ 0x021D8AF8; symbol: func_ov023_021d8af8; size: 0x74.
extern "C" void OV023_ResetSelectionOwner(void *owner) {
    unsigned char *p = (unsigned char *)owner;
    if (ReadCountByteWhenBothOwnerPointersSet((char *)owner + 0x20))
        Object_ResetSelectionAndApplyConfiguredMode((char *)owner + 0x20, 1);
    *(unsigned *)p = 0;
    volatile unsigned *reg = (volatile unsigned *)0x04001000;
    *reg = (*reg & ~0x1f00u) | (*(unsigned *)(p + 0x1c) << 8);
    Object_ResetAndDeactivateState(p + 8);
    InitializeRecordGridAndFlagDefaults(p + 0x20);
    p[0x11a] = 0;
    p[0x11b] = 0;
    p[0x11c] = 0;
    *(unsigned *)p = 0;
    *(unsigned *)(p + 4) = 0;
}
