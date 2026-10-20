#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e9450; symbol: data_020e9450.
// Interleaved signed Q12 sine/cosine lookup table used by Fix32Sin and Fix32Cos. Source definition preserves the complete fixed-point table.
// Initial values: hex 00000010060000100d00001013000010190000101f000010260000102c00001032000010390000103f0000104500ff0f4b00ff0f5200ff0f5800ff0f5e00ff0f ...; full span in module reference.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern volatile short Math_SinCosQ12Table[]; void MTX_Rot22_(int*,int,int); void MTX_ScaleApply22(int*,int*,int,int); int fix32_Divide(int,int); }
// Original: arm9/main @ 0x0205B0D8; symbol: func_0205b0d8; size: 0x9C.
extern "C" void Graphics_BuildRotationScaleAndReciprocalMatrices(void* unused,int* matrix,int* inverse,unsigned char* source) {
 if(source && matrix && inverse) {
  int rotation[4];
  int index=*(unsigned short*)(source+0x1c)>>4;
  index*=2;
  int cosine=Math_SinCosQ12Table[index+1];
  int sine=Math_SinCosQ12Table[index];
  MTX_Rot22_(rotation,sine,cosine);
  MTX_ScaleApply22(rotation,matrix,*(int*)(source+12),*(int*)(source+16));
  int x=fix32_Divide(4096,*(int*)(source+12));
  int y=fix32_Divide(4096,*(int*)(source+16));
  MTX_ScaleApply22(rotation,inverse,x,y);
 }
}
