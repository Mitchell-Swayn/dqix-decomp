#include <globaldefs.h>
ARM
extern "C" void ResetRecordWithInvalidIndex(void *);
extern "C" void _ZN23ZoneContainerRenderPart5ResetEv(void *);
extern "C" void func_ov023_021f71a8(void *, unsigned int);
// Original: arm9/ov023 @ 0x021F6F20; symbol: func_ov023_021f6f20; size: 0x60.
extern "C" int Grotto_InitializeContainerRecord(void *record, unsigned int resource, unsigned int count, unsigned int mode, unsigned int parameter, unsigned int userData) {
    ResetRecordWithInvalidIndex(record);
    *(unsigned short *)((char *)record + 4) = 0;
    *(unsigned short *)((char *)record + 6) = count;
    *(unsigned short *)((char *)record + 8) = mode;
    *(unsigned short *)((char *)record + 0xa) = parameter;
    *(unsigned int *)((char *)record + 0x10) = userData;
    _ZN23ZoneContainerRenderPart5ResetEv((char *)record + 0x20);
    func_ov023_021f71a8(record, resource);
    *(unsigned short *)((char *)record + 0xa8) = 0;
    *(unsigned short *)((char *)record + 0xaa) = 0;
    return 1;
}
