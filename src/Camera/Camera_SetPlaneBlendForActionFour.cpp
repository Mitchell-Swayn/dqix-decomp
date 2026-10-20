#include <globaldefs.h>
ARM
extern "C" void CameraPlaneBlend_CopyConfiguration(void*);
struct State {char pad[0x245];unsigned char flags;char pad246[0x52];char record[1];};
// Original: arm9/main @ 0x020A2908; symbol: func_020a2908; size: 0x20.
extern "C" void Camera_SetPlaneBlendForActionFour(State* p) {
    CameraPlaneBlend_CopyConfiguration(p->record);
    p->flags|=4;
}
