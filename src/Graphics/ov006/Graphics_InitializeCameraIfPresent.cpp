#include <globaldefs.h>
ARM

extern "C" void InitializeStoredVectorsAndInterpolationDefaults(char *);
extern "C" void WriteThreeWordsAtOffsets10Through18(int, unsigned int, unsigned int, unsigned int);
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char *, int, int, int);
extern "C" void Camera_UpdateRenderView(void *);
extern "C" void ClearWordFieldAtOffset238(int);

// Original: arm9/ov006 @ 0x021542F4; symbol: func_ov006_021542f4; size: 0x54.
extern "C" void Graphics_InitializeCameraIfPresent(char *self) {
    if (self == 0) {
        return;
    }
    InitializeStoredVectorsAndInterpolationDefaults(self);
    WriteThreeWordsAtOffsets10Through18((int)self, 0, 0xffffe171, 0);
    ComputeRotatedEndpointFromAngleHeightAndLength(self, 0, 0x2eb8, 0xa000);
    Camera_UpdateRenderView(self);
    ClearWordFieldAtOffset238((int)self);
}
