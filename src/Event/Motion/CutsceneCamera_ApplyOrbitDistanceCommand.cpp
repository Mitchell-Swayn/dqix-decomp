#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02158028; symbol: func_ov001_02158028; size: 0x10.
extern "C" int CutsceneCamera_ApplyOrbitDistanceCommand(void *source, void *destination) {
    *(unsigned int *)((unsigned char *)destination + 0x6c) =
        *(unsigned int *)((unsigned char *)source + 0x1c);
    return 0;
}
