#include <globaldefs.h>
#include "GameState/GameState.h"
ARM
struct Camera;struct GameResources;struct Matrix43;struct Matrix44;struct Vector {int x,y,z;};
struct EdgeColors {unsigned short values[8];};
extern "C" {
void* _ZN9GameState11GetInstanceEv();void* GameState_ReadUnknownB0(GameState*);void Camera_UpdateRenderView(Camera*);
void Graphics_InitializeGeometryAndDisplayState();void Graphics_ResetGeometryMatrixStackState();
void _ZN12RenderConfig5ResetEv();void _ZN12RenderConfig12SubmitToFifoEv();void SendQueuedDataToGeometryFifo();
void Graphics_CopySixteenBytesToEdgeColorRegisters(const void*);void* __clear(void*,unsigned int);
void G3_LookAt(const Vector*,const Vector*,const Vector*,int,Matrix43*);
void Geometry_BuildAndOptionallyApplyProjectionMatrix(int,int,int,int,int,int,int,int,Matrix44*);
void Graphics_WriteSwapControlAndToggleGlobalState(unsigned,unsigned);
void _Z24UpdateAndApplyBrightnessP13GameResources(GameResources*);
void Graphics_DrawSceneOwnersAndOptionalBox(unsigned char*);void CharacterViewer_DrawMenuAndScrollbar(unsigned char*);void Graphics_DrawModelAndAnimationDiagnostics(unsigned char*);
// Original data: arm9/ov015 @ 0x2193d14; symbol: data_ov015_02193d14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000000000000f0ffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
// Original data: arm9/ov015 @ 0x2193d2c; symbol: data_ov015_02193d2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000010000000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
// Original data: arm9/ov015 @ 0x2193d38; symbol: data_ov015_02193d38.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 86108610861086108610861086108610.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern EdgeColors GraphicsRenderSceneAndDiagnosticOverlay_UnknownRoleInitializedBytes_Variant3;extern Vector GraphicsRenderSceneAndDiagnosticOverlay_UnknownRoleInitializedBytes,GraphicsRenderSceneAndDiagnosticOverlay_UnknownRoleInitializedBytes_Variant2;
}
#define DISP3D (*(volatile unsigned short*)0x04000060)
#define MTX_MODE (*(volatile unsigned*)0x04000440)
// Original: arm9/ov015 @ 0x021901C8; symbol: func_ov015_021901c8; size: 0x180.
// Renders the scene using the game camera, then draws the diagnostic overlay with a fixed view and projection.
extern "C" void Graphics_RenderSceneAndDiagnosticOverlay(unsigned char* self) {
 void* game=_ZN9GameState11GetInstanceEv();if(!game)return;
 Graphics_InitializeGeometryAndDisplayState();Graphics_ResetGeometryMatrixStackState();_ZN12RenderConfig5ResetEv();
 DISP3D=(DISP3D&~0x3000)|8;DISP3D=(DISP3D&~0x3000)|0x10;DISP3D=(DISP3D&~0x3000)|0x20;
 EdgeColors edges=GraphicsRenderSceneAndDiagnosticOverlay_UnknownRoleInitializedBytes_Variant3;
 Graphics_CopySixteenBytesToEdgeColorRegisters(&edges);
 void* camera=GameState_ReadUnknownB0((GameState*)game);if(camera)Camera_UpdateRenderView((Camera*)camera);
 _ZN12RenderConfig12SubmitToFifoEv();SendQueuedDataToGeometryFifo();Graphics_DrawSceneOwnersAndOptionalBox(self);
 Graphics_InitializeGeometryAndDisplayState();Graphics_ResetGeometryMatrixStackState();MTX_MODE=0;
 Vector up=GraphicsRenderSceneAndDiagnosticOverlay_UnknownRoleInitializedBytes;
 Vector zero;__clear(&zero,12);
 Vector eye=GraphicsRenderSceneAndDiagnosticOverlay_UnknownRoleInitializedBytes_Variant2;
 G3_LookAt(&zero,&eye,&up,1,0);
 Geometry_BuildAndOptionallyApplyProjectionMatrix(0,0xc0000,0,0x100000,-0x400000,0x400000,0x400000,1,0);
 MTX_MODE=2;CharacterViewer_DrawMenuAndScrollbar(self);Graphics_DrawModelAndAnimationDiagnostics(self);
 Graphics_WriteSwapControlAndToggleGlobalState(1,0);_Z24UpdateAndApplyBrightnessP13GameResources((GameResources*)self);
}
