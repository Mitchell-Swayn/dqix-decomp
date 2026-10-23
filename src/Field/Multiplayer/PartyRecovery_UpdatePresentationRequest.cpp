#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Timing.h>
ARM
struct Object;
extern "C" {
void* Object_GetGlobalSixteenEntryDisplayState();
void* Network_GetConnectionManager();
bool Network_IsSessionActive(int*);
void BackgroundLoader_RemoveObjectTaskAndResetLoadFields(Object3D*);
void GameObject_DisableMovementInput(Object*,int);
void LoadAndApplyPartyDisplayResource(unsigned char*);
void Resource_StartHandleAndCaptureTimestamp(unsigned char*);
void GameState_ProcessPartyDescriptorAndCaptureZone(char*);
int GameState_CountObjectsInD0ThroughDFSlots(void*);
void Resource_DestroyAndFreeAllocatedObject(char*);
void FileCache_RestoreRomTablesIfSpaceAvailable();
void GameObject_RequestMovementInputEnable(int);
}
// Original: arm9/ov017 @ 0x021C2F3C; symbol: PartyRecovery_UpdatePresentationRequest; size: 0x1BC.
extern "C" void PartyRecovery_UpdatePresentationRequest(unsigned char* self){
GameObject* protagonist=GameState::GetInstance()->GetUnknownGameObject();void* display=Object_GetGlobalSixteenEntryDisplayState();int* network=(int*)Network_GetConnectionManager();
if(!protagonist)self[0x8c]=3;
if(self[0x8c]==0){
if(protagonist){BackgroundLoader_RemoveObjectTaskAndResetLoadFields(&protagonist->obj3D_);GameObject_DisableMovementInput((Object*)protagonist,1);}
if(protagonist->obj3D_.GetField06()==10000||protagonist->obj3D_.GetField06()==10100){self[0x8c]=2;return;}
if(self[0x94]==0)self[0x8c]=1;
else if(self[0x94]==1){if(Network_IsSessionActive(network))self[0x8c]=2;else self[0x8c]=3;}
}else if(self[0x8c]==1){LoadAndApplyPartyDisplayResource(self);if(*(unsigned*)(self+0x90))self[0x8c]=2;
}else if(self[0x8c]==2){if(self[0x94]==0)Resource_StartHandleAndCaptureTimestamp(self);else if(self[0x94]==1)GameState_ProcessPartyDescriptorAndCaptureZone((char*)self);
}else if(self[0x8c]==3){
if(*(unsigned*)(self+0x90)&&GameState_CountObjectsInD0ThroughDFSlots(display)>0)return;
if(((GetCurrentTimestamp()-*(unsigned long long*)(self+0x98))<<6)/33514<1200)return;
self[1]=1;Resource_DestroyAndFreeAllocatedObject((char*)self);if(self[0x96])FileCache_RestoreRomTablesIfSpaceAvailable();if(protagonist)GameObject_RequestMovementInputEnable((int)protagonist);
}
}
