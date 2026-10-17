#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void SetMainLoopCallback(void*);
extern "C" unsigned int data_ov031_02290c94;
extern "C" void func_ov031_0222ce24(void);
// Original: arm9/ov031 @ 0x0222D6DC; symbol: func_ov031_0222d6dc; size: 0x44.
extern "C" void func_ov031_0222d6dc(void) {
    if (HasSharedObjectPointer()) return;
    unsigned int* object = *(unsigned int**)&data_ov031_02290c94;
    unsigned int* field = *(unsigned int**)((char*)object + 4);
    *field &= 0xc1fffcff;
    SetMainLoopCallback((void*)func_ov031_0222ce24);
}
