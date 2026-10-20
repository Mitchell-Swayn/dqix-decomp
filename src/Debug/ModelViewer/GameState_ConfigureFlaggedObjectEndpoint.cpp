#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetManualControlCamera(void *);
extern "C" void Camera_InitializeManualControlState(int);
extern "C" void Camera_SetManualControlMode(int, unsigned);
extern "C" void Camera_GetOrbitParameters(int *, int *, int *, int *);
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char *, int, int, int);
// Original: arm9/ov015 @ 0x02192544; symbol: func_ov015_02192544; size: 0x64.
extern "C" void GameState_ConfigureFlaggedObjectEndpoint(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    if (state == 0) return;
    void *object = GameState_GetManualControlCamera(state);
    if (object == 0) return;
    Camera_InitializeManualControlState((int)object);
    Camera_SetManualControlMode((int)object, 2);
    int x;
    int y;
    int z;
    Camera_GetOrbitParameters((int *)object, &x, &y, &z);
    ComputeRotatedEndpointFromAngleHeightAndLength((char *)object, x, 0x13D7, z);
}
