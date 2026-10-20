#include <globaldefs.h>
ARM
struct CubicPath;
extern "C" int AdvanceCubicPathByMinimumDistance(CubicPath *track);
extern "C" void CubicPath_ReadCurrentPosition(void *track, unsigned *output);
// Original: arm9/ov001 @ 0x02157890; symbol: func_ov001_02157890; size: 0x78.
// Checks two cubic tracks, clears their shared status when both finish, and writes both outputs.
extern "C" void CubicPath_AdvancePairedTracksAndReadPositions(char *object, unsigned *firstOutput, unsigned *secondOutput) {
    if (!*(unsigned *)(object + 0x8c0)) return;
    int firstReady = 0;
    int secondReady = 0;
    if (AdvanceCubicPathByMinimumDistance((CubicPath*)(object + 0x188))) firstReady = 1;
    if (AdvanceCubicPathByMinimumDistance((CubicPath*)(object + 0x524))) secondReady = 1;
    if (firstReady && secondReady) *(unsigned *)(object + 0x8c0) = 0;
    CubicPath_ReadCurrentPosition(object + 0x188, firstOutput);
    CubicPath_ReadCurrentPosition(object + 0x524, secondOutput);
}
