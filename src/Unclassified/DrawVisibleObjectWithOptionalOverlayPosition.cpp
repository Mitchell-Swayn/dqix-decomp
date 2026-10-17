#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#pragma block_assign on
#include <World/Object3D.h>
#include <GameState/GameState.h>
#include <Graphics/NSBXX/RenderConfig.h>
struct Vec{int x,y,z;};extern Vec data_020e8920;extern "C" int Object3D_DrawWithTemporaryHeightAndCameraDisplacement(void*,unsigned,int);extern "C" void* GameState_ReadUnknownB0(GameState*);extern "C" void* Object_GetSubrecordAtOffset144(void*);extern "C" void MI_Copy36B(void*,void*),func_02047448(unsigned,int,int);
// Original: arm9/main @ 0x02076BEC; symbol: func_02076bec; size: 0xD8.
extern "C" int DrawVisibleObjectWithOptionalOverlayPosition(unsigned char* object,unsigned arg){if(!((Object3D*)object)->IsVisible())return 0;int result=Object3D_DrawWithTemporaryHeightAndCameraDisplacement(object,arg,0);if(!object[0x17a])return result;{void* member=GameState_ReadUnknownB0(GameState::GetInstance());Vec position=*(Vec*)(object+0x44);position.y=*(int*)(object+0x170);RenderConfig::SetObjectPosition((Vector3fix*)&position);if(member){MI_Copy36B(Object_GetSubrecordAtOffset144(member),&data_0210a010.objectRotationPosition);data_0210a010.flags &= ~0xa4;}Vec scale=data_020e8920;RenderConfig::SetObjectScale((Vector3fix*)&scale);RenderConfig::SubmitToFifo();func_02047448(*(unsigned*)(object+0x16c),0,1);}return result;}
