#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void Object_InitializeTransformScaleAndRenderDefaults(char* p);
// Original: arm9/main @ 0x0203C794; symbol: func_0203c794; size: 0x84.
extern "C" void Object_InitializeRandomizedValue(char *self) {
    Object_InitializeTransformScaleAndRenderDefaults(self);
    *(int *)(self + 0x60) = 0;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0x324;
    *(int *)(self + 0x84) = (int)(4096.0f * ((float)(rand() % 200) / 100.0f));
    *(int *)(self + 0x5c) = 0;
    *(int *)(self + 0x88) = 0;
    *(int *)(self + 0x8c) = 0x7a;
    *(int *)(self + 0x90) = 0;
    *(unsigned char *)(self + 0x94) = 15;
    *(unsigned char *)(self + 0x95) = 0;
    *(int *)(self + 0x98) = 0;
}
