#include <globaldefs.h>
ARM
extern "C" unsigned ReadOverlayControlSecondWord(void);
extern "C" void func_ov000_021639b4(unsigned value);
// Original: arm9/ov025 @ 0x021EB00C; symbol: func_ov025_021eb00c; size: 0x38.
extern "C" void Overlay_RefreshControlOnceForObject(void *object) {
    unsigned char *bytes = (unsigned char *)object;
    if (*(unsigned *)(bytes + 0x0c) == 0) return;
    unsigned *flags = (unsigned *)(bytes + 0x1c4);
    if (*flags & 4) return;
    func_ov000_021639b4(ReadOverlayControlSecondWord());
    *flags |= 4;
}
