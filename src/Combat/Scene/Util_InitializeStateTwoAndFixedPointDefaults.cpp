#include <globaldefs.h>
ARM
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void Camera_SetObjectFlags(void*, unsigned int);
extern "C" void Camera_InitializeManualControlState(int object);
// Original: arm9/ov000 @ 0x0216D2D0; symbol: func_ov000_0216d2d0; size: 0x98.
extern "C" void Util_InitializeStateTwoAndFixedPointDefaults(char *self) {
    Camera_InitializeManualControlState((int)self);
    Camera_SetObjectFlags(self, 8);
    *(int*)(self+0x21c)=0;
    self[0x220]=0;
    self[0x221]=0;
    *(int*)(self+0x224)=-1;
    *(int*)(self+0x228)=4096;
    *(int*)(self+0x22c)=4096;
    *(int*)(self+0x230)=4096;
    *(int*)(self+0x234)=4096;
    *(int*)(self+0x238)=0;
    *(int*)(self+0x23c)=0;
    *(int*)(self+0x240)=0;
    *(int*)(self+0x244)=0;
    *(int*)(self+0x248)=0;
    *(int*)(self+0x24c)=0;
    *(int*)(self+0x250)=0;
    *(int*)(self+0x254)=0;
    *(int*)(self+0x25c)=0;
    *(int*)(self+0x258)=0;
    memset(self+0x260,0,4);
    memset(self+0x264,0,20);
    self[0x278]=0;
    *(int*)(self+0x27c)=0;
}
