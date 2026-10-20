#include <globaldefs.h>
#include <Graphics/NSBXX/GeometryFifo.h>
#include <Graphics/NSBXX/RenderConfig.h>
ARM
// Original data: arm9/ov006 @ 0x2160380; symbol: data_ov006_02160380.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x216038c; symbol: data_ov006_0216038c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern "C" {extern Matrix4x3* GraphicsCaptureMatchingSlotMatrices_UnknownRoleZeroInitializedStorage[3];extern unsigned KrakPotAdvanceSceneResourceLoading_UnknownRoleZeroInitializedStorage[3];void Mat4x3_Multiply(const Matrix4x3*,const Matrix4x3*,Matrix4x3*);}
inline int Slot(unsigned char* p){return (*(unsigned*)(p+8)&0x10)?p[0xae]:-1;}
// Original: arm9/ov006 @ 0x0215426C; symbol: func_ov006_0215426c; size: 0x88.
extern "C" void Graphics_CaptureMatchingSlotMatrices(unsigned char* p){
if(!(*(unsigned*)(p+8)&0x10))return;
for(int i=0;i<3;i++) {
if(KrakPotAdvanceSceneResourceLoading_UnknownRoleZeroInitializedStorage[i]!=Slot(p))continue;
if(GraphicsCaptureMatchingSlotMatrices_UnknownRoleZeroInitializedStorage[i]){
GetCurrentPositionAndDirectionMatrices(GraphicsCaptureMatchingSlotMatrices_UnknownRoleZeroInitializedStorage[i],0);
const Matrix4x3* view=RenderConfig::GetInverseViewMatrix();
Mat4x3_Multiply(GraphicsCaptureMatchingSlotMatrices_UnknownRoleZeroInitializedStorage[i],view,GraphicsCaptureMatchingSlotMatrices_UnknownRoleZeroInitializedStorage[i]);
}
}
}
