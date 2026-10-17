#include <globaldefs.h>
ARM
extern "C" { extern volatile short data_020e9450[]; void func_020c111c(int*,int,int); void MTX_ScaleApply22(int*,int*,int,int); int fix32_Divide(int,int); }
// Original: arm9/main @ 0x0205B0D8; symbol: func_0205b0d8; size: 0x9C.
extern "C" void Graphics_BuildRotationScaleAndReciprocalMatrices(void* unused,int* matrix,int* inverse,unsigned char* source) {
 if(source && matrix && inverse) {
  int rotation[4];
  int index=*(unsigned short*)(source+0x1c)>>4;
  index*=2;
  int cosine=data_020e9450[index+1];
  int sine=data_020e9450[index];
  func_020c111c(rotation,sine,cosine);
  MTX_ScaleApply22(rotation,matrix,*(int*)(source+12),*(int*)(source+16));
  int x=fix32_Divide(4096,*(int*)(source+12));
  int y=fix32_Divide(4096,*(int*)(source+16));
  MTX_ScaleApply22(rotation,inverse,x,y);
 }
}
