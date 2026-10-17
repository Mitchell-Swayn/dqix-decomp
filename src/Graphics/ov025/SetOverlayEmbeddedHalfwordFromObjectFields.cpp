#include <globaldefs.h>
ARM
extern "C" unsigned ReadOverlayControlSecondWord(void);
extern "C" void *GetEmbeddedFieldC18(unsigned char *);
extern "C" void SetHalfwordValueImmediatelyOrWithCount(unsigned char *, short, int);
// Original: arm9/ov025 @ 0x021E8584; symbol: func_ov025_021e8584; size: 0x24.
extern "C" int SetOverlayEmbeddedHalfwordFromObjectFields(void *object) {
    unsigned int control = ReadOverlayControlSecondWord();
    void *embedded = GetEmbeddedFieldC18((unsigned char *)control);
    SetHalfwordValueImmediatelyOrWithCount((unsigned char *)embedded, *(short *)((char *)object + 8), *(unsigned short *)((char *)object + 0xa));
    return 1;
}
