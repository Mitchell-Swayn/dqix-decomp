#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#pragma block_assign on
#include <World/Object3D.h>
#include <GameState/GameState.h>
#include <Graphics/NSBXX/RenderConfig.h>
// Original data: arm9/main @ 0x20e8920; symbol: data_020e8920.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex c8000000c8000000c8000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Vec{int x,y,z;};extern Vec DrawVisibleObjectWithOptionalOverlayPosition_UnknownRoleInitializedBytes;extern "C" int Object3D_DrawWithTemporaryHeightAndCameraDisplacement(void*,unsigned,int);extern "C" void* GameState_ReadUnknownB0(GameState*);extern "C" void* Camera_GetInverseViewRotation(void*);extern "C" void MI_Copy36B(void*,void*),Graphics_DrawEnabledFrameEntryWithTransform(unsigned,int,int);
// Original: arm9/main @ 0x02076BEC; symbol: func_02076bec; size: 0xD8.
extern "C" int DrawVisibleObjectWithOptionalOverlayPosition(unsigned char* object,unsigned arg){if(!((Object3D*)object)->IsVisible())return 0;int result=Object3D_DrawWithTemporaryHeightAndCameraDisplacement(object,arg,0);if(!object[0x17a])return result;{void* member=GameState_ReadUnknownB0(GameState::GetInstance());Vec position=*(Vec*)(object+0x44);position.y=*(int*)(object+0x170);RenderConfig::SetObjectPosition((Vector3fix*)&position);if(member){MI_Copy36B(Camera_GetInverseViewRotation(member),&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectRotationPosition);RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags &= ~0xa4;}Vec scale=DrawVisibleObjectWithOptionalOverlayPosition_UnknownRoleInitializedBytes;RenderConfig::SetObjectScale((Vector3fix*)&scale);RenderConfig::SubmitToFifo();Graphics_DrawEnabledFrameEntryWithTransform(*(unsigned*)(object+0x16c),0,1);}return result;}
