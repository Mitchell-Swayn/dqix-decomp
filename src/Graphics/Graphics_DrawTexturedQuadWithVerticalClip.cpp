#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Flag {unsigned char hidden:1,rest:7;};
struct Sprite {int first;unsigned texture;int state,x,y;short z;Flag flags;};
// Original data: arm9/main @ 0x21077fc; symbol: data_021077fc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned TextLayoutRenderVisibleStream_UnknownRoleZeroInitializedStorage;
extern "C" float _fflt(int);
extern "C" float _fmul(float,float);
extern "C" float _fsub(float,float);
extern "C" float _fdiv(float,float);
extern "C" int _ffix(float);
extern "C" void Graphics_WriteReducedXYVertex(int,int);
// Original: arm9/main @ 0x020417B0; symbol: func_020417b0; size: 0x244.
extern "C" void Graphics_DrawTexturedQuadWithVerticalClip(Sprite* object,unsigned color,int* clip,unsigned alpha) {
 if(object->state<0)return;
 if(object->flags.hidden)return;
 if(!alpha)return;
 float fraction=0.0f;
 volatile unsigned* regs=(volatile unsigned*)0x04000444;
 regs[0]=0;
 int z=object->z+1024;
 int x=object->x,y=object->y;
 regs[11]=x<<12;
 regs[11]=y<<12;
 regs[11]=z<<12;
 regs[10]=4096;regs[10]=4096;regs[10]=4096;
 regs[0]=0;
 regs[11]=0;regs[11]=65536;regs[11]=0;
 regs[10]=4096;regs[10]=-4096;regs[10]=4096;
 regs[0]=0;
 regs[31]=0x7fffffff;
 regs[32]=0x4210;
 regs[25]=0x6c900000|(object->texture>>3);
 regs[26]=TextLayoutRenderVisibleStream_UnknownRoleZeroInitializedStorage>>4;
 regs[24]=0x3e0000c0|(alpha<<16);
 regs[10]=65536;regs[10]=65536;regs[10]=4096;
 regs[47]=1;
 regs[15]=color;
 int margin=_ffix(_fmul(_fflt(16),fraction));
 fraction=_fsub(1.0f,fraction);
 if(clip) {
 if(object->y<clip[1])margin+=clip[1]-object->y;
 if(margin>16)margin=16;
 fraction=_fdiv(_fsub(16.0f,_fflt(margin)),16.0f);
 }
 Graphics_WriteReducedXYVertex(0,margin<<12);
 volatile unsigned* vertex=(volatile unsigned*)0x0400048c;
 unsigned short coord=_ffix(_fmul(4096.0f,fraction));
 vertex[0]=coord<<16;vertex[0]=0;
 Graphics_WriteReducedXYVertex(65536,margin<<12);
 coord=_ffix(_fmul(4096.0f,fraction));
 vertex[0]=(coord<<16)|4096;vertex[0]=0;
 Graphics_WriteReducedXYVertex(65536,65536);
 vertex[0]=4096;vertex[0]=0;
 Graphics_WriteReducedXYVertex(0,65536);
 vertex[0]=0;vertex[0]=0;vertex[30]=0;
 *(volatile unsigned*)0x04000448=1;*(volatile unsigned*)0x04000448=1;*(volatile unsigned*)0x04000448=1;
}
