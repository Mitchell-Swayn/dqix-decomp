#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN8Object3D10InitializeEv(void*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
// Original: arm9/ov003 @ 0x0217BCB8; symbol: func_ov003_0217bcb8; size: 0x80.
extern "C" void Graphics_InitializeObjectAndTwoCanvasTransfers(char* p) {
 *(int*)p=0;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+4);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x18);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x2c);
 Graphics_InitializeCanvasTransferState(p+0x40);
 Graphics_InitializeCanvasTransferState(p+0x60);
 _ZN8Object3D10InitializeEv(p+0x80);
 p[0x12c]=0;
 p[0x12d]=-1;
 *(int*)(p+0x130)=-1;
 *(int*)(p+0x134)=-1;
 *(int*)(p+0x138)=-1;
 *(int*)(p+0x13c)=-1;
 p[0x140]=0; p[0x141]=0; p[0x143]=0; p[0x142]=0;
 *(int*)(p+0x160)=0;
 *(short*)(p+0x15c)=0;
}
