#include <globaldefs.h>
ARM
extern "C" void Object3D_CopyRotationVector(void *, unsigned);
// Original: arm9/ov023 @ 0x021E6088; symbol: func_ov023_021e6088; size: 0x3C.
extern "C" void CharacterPreview_SetBodyRotation(void *obj, unsigned value) {
    Object3D_CopyRotationVector(obj, value);
    Object3D_CopyRotationVector((char *)obj + 0x408, value);
    Object3D_CopyRotationVector((char *)obj + 0xac, value);
    Object3D_CopyRotationVector((char *)obj + 0x35c, value);
}
