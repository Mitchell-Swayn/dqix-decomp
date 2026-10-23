#include <globaldefs.h>
ARM
extern "C" int _Z8fix32cosi(int);
extern "C" int _Z8fix32sini(int);
extern "C" int Field_ScaleLeaderMovementStepForDirection(void*, const void*, int, int, unsigned char);
// Original: arm9/ov017 @ 0x0218DA48; symbol: BuildRotationVectorFromFixedPointAngle; size: 0x60.
// Builds {sin(angle),0,cos(angle)} in fixed point and forwards the vector and remaining arguments.
extern "C" int BuildRotationVectorFromFixedPointAngle(void* self, int angle, int arg2, int arg3, unsigned char flag) {
    int vector[3];
    int cosine = _Z8fix32cosi(angle);
    int sine = _Z8fix32sini(angle);
    vector[0] = sine;
    vector[1] = 0;
    vector[2] = cosine;
    return Field_ScaleLeaderMovementStepForDirection(self, vector, arg2, arg3, flag);
}
