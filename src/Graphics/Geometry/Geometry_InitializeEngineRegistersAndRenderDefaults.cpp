#pragma opt_lifetimes off
#pragma opt_repositioncode off
#include <globaldefs.h>
ARM
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
extern "C" void Graphics_SubmitGeometryAndWaitUntilNotBusy(); extern "C" void Geometry_ResetMatrixStacksAndIdentities(); extern "C" void Graphics_ClearEdgeFogAndToonRegisterTables();
// Original: arm9/main @ 0x020C51DC; symbol: func_020c51dc; size: 0x10C.
extern "C" void Geometry_InitializeEngineRegistersAndRenderDefaults() {
 Graphics_SubmitGeometryAndWaitUntilNotBusy();
 volatile u32 *a=(volatile u32*)0x04000504; *a=0;
 while(a[0x3f]&0x08000000) {}
 volatile u16 *b=(volatile u16*)0x04000060; *b=0; a[0x3f]=0; *(volatile u32*)0x04000010=0;
 *b |= 0x2000; *b |= 0x1000; *b &= 0xffffcffd; *b=(*b&~0x3000)|0x10; *b &= 0xcffb;
 a[0x3f] |=0x8000; a[0x3f]=(a[0x3f]&~0xc0000000)|0x80000000;
 Geometry_ResetMatrixStacksAndIdentities(); volatile u32 *c=(volatile u32*)0x04000350;
 c[0]=0; *(volatile u16*)(c+1)=0x7fff; ((volatile u16*)c)[3]=0; c[2]=0; *(volatile u16*)(c+3)=0; *(volatile u16*)0x04000008 &=~3;
 Graphics_ClearEdgeFogAndToonRegisterTables(); volatile u32 *d=(volatile u32*)0x040004a4; d[0]=0x1f0080;d[1]=0;d[2]=0;
}
