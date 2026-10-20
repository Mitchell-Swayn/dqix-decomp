#include <globaldefs.h>
ARM
extern "C" void ProfileEditor_ResetComponentTransfers(unsigned char *);
// Original: arm9/ov017 @ 0x021C19E0; symbol: func_ov017_021c19e0; size: 0x18.
extern "C" void ProfileScreen_RefreshOptionalComponents(void *p) {
    unsigned char *screen = *(unsigned char **)((unsigned char *)p + 0x20);
    if (screen) ProfileEditor_ResetComponentTransfers(screen);
}
