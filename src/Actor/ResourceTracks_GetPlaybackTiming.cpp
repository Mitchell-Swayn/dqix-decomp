#include <globaldefs.h>
#pragma optimization_level 4
extern "C" int ResourceTracks_GetResolvedResourceTable();
// Original: arm9/main @ 0x020550F0; symbol: func_020550f0; size: 0x18.
extern "C" unsigned int ResourceTracks_GetPlaybackTiming() {
    int object = ResourceTracks_GetResolvedResourceTable();
    if (object == 0) return 0;
    return *(unsigned int*)(object + 0x10);
}
