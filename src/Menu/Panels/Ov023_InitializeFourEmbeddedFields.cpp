#include <globaldefs.h>
extern "C" void __clear(void *, unsigned int);
extern "C" void Object3D_CopyRotationVector(void *, const void *);
// Original: arm9/ov023 @ 0x021E60E0; symbol: func_ov023_021e60e0; size: 0x5C.
extern "C" void Ov023_InitializeFourEmbeddedFields(char *object, unsigned int value) {
    unsigned int temp[3];
    __clear(temp, 0x0c);
    temp[1] = value;
    Object3D_CopyRotationVector(object, temp);
    Object3D_CopyRotationVector(object + 0x408, temp);
    Object3D_CopyRotationVector(object + 0xac, temp);
    Object3D_CopyRotationVector(object + 0x35c, temp);
}
