#include <globaldefs.h>
ARM
extern "C" short FieldInteraction_ComputeSignedFacingAngleToTarget(void *, int, void *);
extern "C" int _Z8fix32absi(int);
// Original: arm9/ov017 @ 0x021A4754; symbol: func_ov017_021a4754; size: 0x18.
extern "C" short GetAbsoluteSignedAngleToTargetVector(void *a, int angle, void *out) {
    return (short)_Z8fix32absi(FieldInteraction_ComputeSignedFacingAngleToTarget(a, angle, out));
}
