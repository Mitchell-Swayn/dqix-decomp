#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void* GameState_ReadPResources(GameState*);extern "C" void GameState_InitializeEquipmentEntry(void*),Field_QueueChurchServiceMenu(void*),GameState_CreateAndAppendIndexedObject(void*),FieldFacilityMenu_QueueOverlayCommand(void*),Field_QueuePartyManagementWhenMembersResolved(void*,int),World_SetIndexedByteValue(void*,int),World_SetKind2BByte(void*,int),FieldScreen_QueueOverlayThreeSession(void*,int,int),Resource_CreateLinkedByteRecord(void*,int,int,int,int,int);
// Original: arm9/main @ 0x0206F6CC; symbol: func_0206f6cc; size: 0x128.
extern "C" int DispatchIndexedByteOpcodeToWorldState(unsigned char* p,int index){
 if(index<0||*(int*)(p+4)<=index)return 1;void* state=GameState_ReadPResources(GameState::GetInstance());switch(p[index]){
 case 1:GameState_InitializeEquipmentEntry(state);break;case 2:Field_QueueChurchServiceMenu(state);break;case 3:GameState_CreateAndAppendIndexedObject(state);break;case 4:FieldFacilityMenu_QueueOverlayCommand(state);break;case 5:Field_QueuePartyManagementWhenMembersResolved(state,0);break;case 6:World_SetIndexedByteValue(state,3);break;case 7:World_SetKind2BByte(state,0);break;case 8:Field_QueuePartyManagementWhenMembersResolved(state,1);break;case 9:FieldScreen_QueueOverlayThreeSession(state,0,0);break;case 10:FieldScreen_QueueOverlayThreeSession(state,1,0);break;case 11:Resource_CreateLinkedByteRecord(state,0,1,2,3,4);break;case 12:World_SetIndexedByteValue(state,3);break;default:return 1;}return 0;
}
