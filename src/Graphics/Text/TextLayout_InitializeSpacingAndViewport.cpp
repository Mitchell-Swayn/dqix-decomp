#include <globaldefs.h>
extern "C" void TextWindow_SetViewportRectangle(void*,int,int,int,int);
// Original: arm9/main @ 0x02042B3C; symbol: func_02042b3c; size: 0x5C.
extern "C" void TextLayout_InitializeSpacingAndViewport(unsigned char* p) { *(int*)(p+6240)=12; *(int*)(p+6244)=16; TextWindow_SetViewportRectangle(p,2,146,252,74); p[6578]=0; p[6577]=0; p[6491]|=2; }
