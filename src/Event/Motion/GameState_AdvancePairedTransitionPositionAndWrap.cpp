#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" int ConfigurePairedCubicTracksForDuration(char*);
extern "C" void CubicPath_AdvancePairedTracksAndReadPositions(char*,unsigned*,unsigned*);
// Original: arm9/ov001 @ 0x02158384; symbol: func_ov001_02158384; size: 0xEC.
typedef Vector3fix Position;
// Advances paired cubic tracks, updates a wrapped position, and clears the active flag when the transition ends.
extern "C" int GameState_AdvancePairedTransitionPositionAndWrap(void* unused, char* self) {
    if (*(int*)(self + 0x38) <= 0) {
        ConfigurePairedCubicTracksForDuration(self + 0x15c);
        *(int*)(self + 0xa1c) = 1;
        *(int*)(self + 0x38) = 1;
    }
    Position first, second, position;
    CubicPath_AdvancePairedTracksAndReadPositions(self + 0x15c, (unsigned *)&first, (unsigned *)&second);
    position.x = *(int*)(self + 0x64);
    position.y = *(int*)(self + 0x68);
    position.z = *(int*)(self + 0x6c);
    Vector3fix_Subtract(&first, &position, (Vector3fix *)(self + 0x128));
    Vector3fix_Subtract(&second, (Vector3fix *)(self + 0x58), (Vector3fix *)(self + 0x11c));
    memcpy((void *)&position, &first, 12);
    memcpy(self + 0x58, &second, 12);
    if (position.x >= 0x647a) position.x -= 0x647a;
    *(int*)(self + 0x64) = position.x;
    *(int*)(self + 0x68) = position.y;
    *(int*)(self + 0x6c) = position.z;
    int result = *(int*)(self + 0xa1c) ? 0 : 1;
    if (result) { result = 0; *(int*)(self + 0x38) = 0; } else result = 1;
    return result;
}
