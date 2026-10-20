#include <globaldefs.h>
ARM
struct Object3D { void Initialize(); };
// Original: arm9/ov023 @ 0x021FCE28; symbol: func_ov023_021fce28; size: 0x10.
extern "C" void Ov023_InitializeEmbeddedObject3D(Object3D *owner) {
    ((Object3D *)((char *)owner + 0x20))->Initialize();
}
