#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void* GameState_ReadPResources(GameState*);extern "C" void GameState_InitializeEquipmentEntry(void*),GameState_InitializeAndAppendType16Record(void*),GameState_CreateAndAppendIndexedObject(void*),func_ov017_021b2c24(void*),func_ov017_021b65e0(void*,int),World_SetIndexedByteValue(void*,int),World_SetKind2BByte(void*,int),func_ov017_021c12fc(void*,int,int),Resource_CreateLinkedByteRecord(void*,int,int,int,int,int);
// Original: arm9/main @ 0x0206F6CC; symbol: func_0206f6cc; size: 0x128.
extern "C" int DispatchIndexedByteOpcodeToWorldState(unsigned char* p,int index){
 if(index<0||*(int*)(p+4)<=index)return 1;void* state=GameState_ReadPResources(GameState::GetInstance());switch(p[index]){
 case 1:GameState_InitializeEquipmentEntry(state);break;case 2:GameState_InitializeAndAppendType16Record(state);break;case 3:GameState_CreateAndAppendIndexedObject(state);break;case 4:func_ov017_021b2c24(state);break;case 5:func_ov017_021b65e0(state,0);break;case 6:World_SetIndexedByteValue(state,3);break;case 7:World_SetKind2BByte(state,0);break;case 8:func_ov017_021b65e0(state,1);break;case 9:func_ov017_021c12fc(state,0,0);break;case 10:func_ov017_021c12fc(state,1,0);break;case 11:Resource_CreateLinkedByteRecord(state,0,1,2,3,4);break;case 12:World_SetIndexedByteValue(state,3);break;default:return 1;}return 0;
}
