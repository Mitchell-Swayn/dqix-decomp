#include <globaldefs.h>
ARM

extern "C" void Camera_InitializeTargetFollowingState(char *);
extern "C" void Camera_SetTargetCoordinates(int, unsigned int, unsigned int, unsigned int);
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char *, int, int, int);
extern "C" void Camera_UpdateRenderView(void *);
extern "C" void Camera_DisableTargetFollowing(int);

// Original: arm9/ov006 @ 0x021542F4; symbol: func_ov006_021542f4; size: 0x54.
extern "C" void Graphics_InitializeCameraIfPresent(char *self) {
    if (self == 0) {
        return;
    }
    Camera_InitializeTargetFollowingState(self);
    Camera_SetTargetCoordinates((int)self, 0, 0xffffe171, 0);
    ComputeRotatedEndpointFromAngleHeightAndLength(self, 0, 0x2eb8, 0xa000);
    Camera_UpdateRenderView(self);
    Camera_DisableTargetFollowing((int)self);
}
