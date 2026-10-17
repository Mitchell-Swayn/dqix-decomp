#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
extern "C" void _ZN12RenderConfig17SetObjectPositionEP8Vector3i(Vec*);
extern "C" void _ZN12RenderConfig14SetObjectScaleEP8Vector3i(Vec*);
extern "C" void _ZN12RenderConfig12SubmitToFifoEv();
extern "C" void RenderConfig_CopyTransformAndClearFlagsA4(void*);
extern "C" int _Z8fix32sini(int);
extern "C" int _Z8fix32cosi(int);
extern "C" THUMB void MTX_RotY33_(void*,int,int);
extern "C" void Graphics_WriteTextureImageParameterBits(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void Graphics_WritePackedPolygonAttributeFields_Main0208B588(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
ARM
// Original: arm9/main @ 0x0208B610; symbol: func_0208b610; size: 0x178.
extern "C" void Graphics_DrawColoredRotatedBox(Vec position,unsigned color,int sx,int sy,int sz,short angle) {
 int matrix[9];
 _ZN12RenderConfig17SetObjectPositionEP8Vector3i(&position);
 int cosine=_Z8fix32cosi(angle);
 MTX_RotY33_(matrix,_Z8fix32sini(angle),cosine);
 RenderConfig_CopyTransformAndClearFlagsA4(matrix);
 Vec scale={sx,sy,sz};
 _ZN12RenderConfig14SetObjectScaleEP8Vector3i(&scale);
 _ZN12RenderConfig12SubmitToFifoEv();
 Graphics_WriteTextureImageParameterBits(0,0,1,1,0,0,0,0);
 Graphics_WritePackedPolygonAttributeFields_Main0208B588(0,0,3,0,0,0);
 *(volatile unsigned*)0x04000500=1;
 *(volatile unsigned*)0x04000480=color;
 volatile unsigned* v=(volatile unsigned*)0x0400048c;
 *v=0x08000800; *v=0x800;
 *v=0xf8000800; *v=0x800;
 *v=0xf800f800; *v=0x800;
 *v=0x0800f800; *v=0x800;
 *v=0x08000800; *v=0xf800;
 *v=0xf8000800; *v=0xf800;
 *v=0xf800f800; *v=0xf800;
 *v=0x0800f800; *v=0xf800;
 *v=0x08000800; *v=0x800;
 *v=0x08000800; *v=0xf800;
 *v=0xf8000800; *v=0xf800;
 *v=0xf8000800; *v=0x800;
 *v=0x0800f800; *v=0x800;
 *v=0x0800f800; *v=0xf800;
 *v=0xf800f800; *v=0xf800;
 *v=0xf800f800; *v=0x800;
 *(volatile unsigned*)0x04000504=0;
}
