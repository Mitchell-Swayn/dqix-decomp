#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" int CharacterViewer_GetTrackedBoneIndex(char*);
extern "C" const Matrix4x3* _ZN12RenderConfig20GetInverseViewMatrixEv();
extern "C" void _Z38GetCurrentPositionAndDirectionMatricesP9Matrix4x3P9Matrix3x3(Matrix4x3*,Matrix3x3*);
extern "C" void Mat4x3_Multiply(const Matrix4x3*,const Matrix4x3*,Matrix4x3*);
// Original data: arm9/ov015 @ 0x2193fe0; symbol: data_ov015_02193fe0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffff00.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" unsigned char GraphicsCaptureSelectedPositionMatrices_UnknownRoleInitializedBytes[];
// Original data: arm9/ov015 @ 0x2194564; symbol: data_ov015_02194564.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" Matrix4x3* GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov015 @ 0x2194570; symbol: data_ov015_02194570.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
// Original data: arm9/ov015 @ 0x21945a0; symbol: data_ov015_021945a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
// Original data: arm9/ov015 @ 0x21945d0; symbol: data_ov015_021945d0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" Matrix4x3 GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage_Variant2,GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage_Variant3,GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage_Variant4;
// Original: arm9/ov015 @ 0x0218BB3C; symbol: func_ov015_0218bb3c; size: 0x160.
extern "C" void Graphics_CaptureSelectedPositionMatrices(char* self) {
 if(!(*(unsigned*)(self+8)&16))return;
 if(GraphicsCaptureSelectedPositionMatrices_UnknownRoleInitializedBytes[1]==CharacterViewer_GetTrackedBoneIndex(self) && GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[2]) {
  _Z38GetCurrentPositionAndDirectionMatricesP9Matrix4x3P9Matrix3x3(GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[2],0);
  GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage_Variant2=*GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[2];
  const Matrix4x3* inverse=_ZN12RenderConfig20GetInverseViewMatrixEv();
  Mat4x3_Multiply(GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[2],inverse,GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[2]);
 }
 if(GraphicsCaptureSelectedPositionMatrices_UnknownRoleInitializedBytes[2]==CharacterViewer_GetTrackedBoneIndex(self) && GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[0]) {
  _Z38GetCurrentPositionAndDirectionMatricesP9Matrix4x3P9Matrix3x3(GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[0],0);
  GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage_Variant3=*GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[0];
  const Matrix4x3* inverse=_ZN12RenderConfig20GetInverseViewMatrixEv();
  Mat4x3_Multiply(GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[0],inverse,GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[0]);
 }
 if(GraphicsCaptureSelectedPositionMatrices_UnknownRoleInitializedBytes[0]==CharacterViewer_GetTrackedBoneIndex(self) && GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[1]) {
  _Z38GetCurrentPositionAndDirectionMatricesP9Matrix4x3P9Matrix3x3(GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[1],0);
  GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage_Variant4=*GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[1];
  const Matrix4x3* inverse=_ZN12RenderConfig20GetInverseViewMatrixEv();
  Mat4x3_Multiply(GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[1],inverse,GraphicsCaptureSelectedPositionMatrices_UnknownRoleZeroInitializedStorage[1]);
 }
}
