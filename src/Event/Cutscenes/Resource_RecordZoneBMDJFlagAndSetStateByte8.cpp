#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void _ZN6Zone3D20RecordBMDJFlag4StateEv(void *);
extern "C" void *GameResources_GetInstance(void);
// Original: arm9/ov001 @ 0x02163DC8; symbol: Resource_RecordZoneBMDJFlagAndSetStateByte8; size: 0x24.
// Records the Zone BMDJ flag state and sets byte 8 in the resource state at GameResources +0x3B5C.
extern "C" int Resource_RecordZoneBMDJFlagAndSetStateByte8(void) {
    _ZN6Zone3D20RecordBMDJFlag4StateEv(Zone3D_GetMainInstance());
    unsigned char *resources = (unsigned char *)GameResources_GetInstance() + 0x3000;
    unsigned char *state = *(unsigned char **)(resources + 0xb5c);
    state[8] = 1;
    return 1;
}
