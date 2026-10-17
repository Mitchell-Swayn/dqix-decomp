#include <globaldefs.h>
#include <Graphics/NSBXX/GeometryFifo.h>
#include <Graphics/NSBXX/RenderConfig.h>
ARM
extern "C" {extern Matrix4x3* data_ov006_0216038c[3];extern unsigned data_ov006_02160380[3];void Mat4x3_Multiply(const Matrix4x3*,const Matrix4x3*,Matrix4x3*);}
inline int Slot(unsigned char* p){return (*(unsigned*)(p+8)&0x10)?p[0xae]:-1;}
// Original: arm9/ov006 @ 0x0215426C; symbol: func_ov006_0215426c; size: 0x88.
extern "C" void Graphics_CaptureMatchingSlotMatrices(unsigned char* p){
if(!(*(unsigned*)(p+8)&0x10))return;
for(int i=0;i<3;i++) {
if(data_ov006_02160380[i]!=Slot(p))continue;
if(data_ov006_0216038c[i]){
GetCurrentPositionAndDirectionMatrices(data_ov006_0216038c[i],0);
const Matrix4x3* view=RenderConfig::GetInverseViewMatrix();
Mat4x3_Multiply(data_ov006_0216038c[i],view,data_ov006_0216038c[i]);
}
}
}
