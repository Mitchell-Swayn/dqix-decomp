#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" int func_ov015_0218bc9c(char*);
extern "C" const Matrix4x3* _ZN12RenderConfig20GetInverseViewMatrixEv();
extern "C" void _Z38GetCurrentPositionAndDirectionMatricesP9Matrix4x3P9Matrix3x3(Matrix4x3*,Matrix3x3*);
extern "C" void Mat4x3_Multiply(const Matrix4x3*,const Matrix4x3*,Matrix4x3*);
extern "C" unsigned char data_ov015_02193fe0[];
extern "C" Matrix4x3* data_ov015_02194564[];
extern "C" Matrix4x3 data_ov015_02194570,data_ov015_021945a0,data_ov015_021945d0;
// Original: arm9/ov015 @ 0x0218BB3C; symbol: func_ov015_0218bb3c; size: 0x160.
extern "C" void Graphics_CaptureSelectedPositionMatrices(char* self) {
 if(!(*(unsigned*)(self+8)&16))return;
 if(data_ov015_02193fe0[1]==func_ov015_0218bc9c(self) && data_ov015_02194564[2]) {
  _Z38GetCurrentPositionAndDirectionMatricesP9Matrix4x3P9Matrix3x3(data_ov015_02194564[2],0);
  data_ov015_02194570=*data_ov015_02194564[2];
  const Matrix4x3* inverse=_ZN12RenderConfig20GetInverseViewMatrixEv();
  Mat4x3_Multiply(data_ov015_02194564[2],inverse,data_ov015_02194564[2]);
 }
 if(data_ov015_02193fe0[2]==func_ov015_0218bc9c(self) && data_ov015_02194564[0]) {
  _Z38GetCurrentPositionAndDirectionMatricesP9Matrix4x3P9Matrix3x3(data_ov015_02194564[0],0);
  data_ov015_021945a0=*data_ov015_02194564[0];
  const Matrix4x3* inverse=_ZN12RenderConfig20GetInverseViewMatrixEv();
  Mat4x3_Multiply(data_ov015_02194564[0],inverse,data_ov015_02194564[0]);
 }
 if(data_ov015_02193fe0[0]==func_ov015_0218bc9c(self) && data_ov015_02194564[1]) {
  _Z38GetCurrentPositionAndDirectionMatricesP9Matrix4x3P9Matrix3x3(data_ov015_02194564[1],0);
  data_ov015_021945d0=*data_ov015_02194564[1];
  const Matrix4x3* inverse=_ZN12RenderConfig20GetInverseViewMatrixEv();
  Mat4x3_Multiply(data_ov015_02194564[1],inverse,data_ov015_02194564[1]);
 }
}
