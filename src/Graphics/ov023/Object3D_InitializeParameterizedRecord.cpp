#include <globaldefs.h>
ARM
extern "C" void ResetRecordWithInvalidIndex(void*);
extern "C" void _ZN8Object3D10InitializeEv(void*);
extern "C" void func_ov023_021fd03c(void*, void*);
extern "C" int Object3D_InitializeParameterizedRecord(void* self, void* owner, unsigned short value2, unsigned short value3, int value4, unsigned value5);
// Original: arm9/ov023 @ 0x021FCDD4; symbol: func_ov023_021fcdd4; size: 0x54.
extern "C" int Object3D_InitializeParameterizedRecord(void* self, void* owner, unsigned short value2, unsigned short value3, int value4, unsigned value5) {
    ResetRecordWithInvalidIndex(self);
    unsigned char* bytes = (unsigned char*)self;
    *(unsigned short*)(bytes + 4) = 0x14;
    *(unsigned short*)(bytes + 6) = value2;
    *(unsigned short*)(bytes + 8) = value3;
    *(unsigned short*)(bytes + 0xa) = value4;
    *(unsigned*)(bytes + 0x10) = value5;
    _ZN8Object3D10InitializeEv(bytes + 0x20);
    func_ov023_021fd03c(self, owner);
    return 1;
}
