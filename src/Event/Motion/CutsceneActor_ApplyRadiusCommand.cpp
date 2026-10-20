#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x021598E0; symbol: func_ov001_021598e0; size: 0x10.
extern "C" int CutsceneActor_ApplyRadiusCommand(const void *source, void *destination) {
    *(unsigned int *)((char *)destination + 0x90) = *(const unsigned int *)((const char *)source + 0x10);
    return 0;
}
