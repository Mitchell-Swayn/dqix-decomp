#include <globaldefs.h>
ARM
extern "C" void InitializePairedRecordGroups(void *);
// Original: arm9/ov001 @ 0x02158324; symbol: func_ov001_02158324; size: 0x14.
extern "C" int CutsceneCamera_ResetPairedOrbitAndTargetPaths(void *unused, void *object) {
    InitializePairedRecordGroups((unsigned char *)object + 0x15c);
    return 0;
}
