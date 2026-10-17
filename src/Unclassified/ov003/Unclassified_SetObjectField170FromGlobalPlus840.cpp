#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" void func_ov003_0216ffbc(void *);
// Original: arm9/ov003 @ 0x021700BC; symbol: func_ov003_021700bc; size: 0x20.
extern "C" void Unclassified_SetObjectField170FromGlobalPlus840(void *object) {
    *(void **)((unsigned char *)object + 0x170) = (unsigned char *)ReadGlobalValueAt020FB3F0() + 0x840;
    func_ov003_0216ffbc(object);
}
