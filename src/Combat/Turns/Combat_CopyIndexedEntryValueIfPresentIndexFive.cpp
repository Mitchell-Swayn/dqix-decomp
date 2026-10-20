#include <globaldefs.h>
ARM
extern "C" int Overlay_CopyIndexedEntryValueIfPresent(int, unsigned int);
// Original: arm9/ov000 @ 0x02181FB0; symbol: func_ov000_02181fb0; size: 0x14.
extern "C" int Combat_CopyIndexedEntryValueIfPresentIndexFive(unsigned int a, unsigned int b, unsigned int c) { (void)a; (void)b; return Overlay_CopyIndexedEntryValueIfPresent(5, c); }
