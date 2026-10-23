#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
ARM
struct Object;struct State;
extern "C" {
void GameObject_DisableMovementInput(Object*,int);
void* GameState_GetFieldOrbitCamera(void*);
void Camera_SetFollowControlFlags(int,unsigned char);
void Camera_ClearFollowControlFlags(unsigned char*,unsigned char);
int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);
void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
void FileCache_RestoreRomTablesIfSpaceAvailable();
void ResetAllocatorAndStateWithDisabledEntryFlag(State*,int);
void Memory_SafeAllocatorCreateTypeAWith800ByteAllocation(SafeAllocator*,SafeAllocator*);
int GameState_UpdatePartyTransitionDialogue(void*,int);
void BackgroundLoader_CancelTaskAndDestroyDisplayAllocator(SafeAllocator*);
void Memory_ReleaseAllocatorAndSignedAllocation(void*);
void GameObject_RequestMovementInputEnable(void*);
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern SafeAllocator* PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage;
}
// Original: arm9/ov017 @ 0x021C01A4; symbol: PartyTransition_UpdateDialogueRequest; size: 0x178.
extern "C" void PartyTransition_UpdateDialogueRequest(unsigned char* self){
GameState* game=GameState::GetInstance();GameObject* protagonist=game->GetUnknownGameObject();GameObject_DisableMovementInput((Object*)protagonist,1);
unsigned char* camera=(unsigned char*)GameState_GetFieldOrbitCamera(game);Camera_SetFollowControlFlags((int)camera,1);
SafeAllocator* allocator=(SafeAllocator*)(self+8);
int* phase=(int*)(self+0x1c);
if(*phase==0){
Filesystem_FreeCachedTableIfAllocationNeedsSpace(0xc3c);
void* buffer=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,0xc3c);
if(!buffer){FileCache_RestoreRomTablesIfSpaceAvailable();self[1]=1;return;}
allocator->CreateTypeA(buffer,0xc3c);allocator->Reset();
PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage=(SafeAllocator*)allocator->Allocate(0x3c);
if(!PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage){FileCache_RestoreRomTablesIfSpaceAvailable();self[1]=1;return;}
ResetAllocatorAndStateWithDisabledEntryFlag((State*)PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage,(signed char)self[0x20]);
Memory_SafeAllocatorCreateTypeAWith800ByteAllocation(PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage,allocator);++*phase;
}else if(*phase==1){unsigned elapsed=GameState::GetInstance()->GetTickCount();if(GameState_UpdatePartyTransitionDialogue(PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage,elapsed))++*phase;
}else if(*phase==2){BackgroundLoader_CancelTaskAndDestroyDisplayAllocator(PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage);++*phase;
}else if(*phase==3){Memory_ReleaseAllocatorAndSignedAllocation(self);Camera_ClearFollowControlFlags(camera,1);GameObject_RequestMovementInputEnable(protagonist);++*phase;self[1]=1;FileCache_RestoreRomTablesIfSpaceAvailable();}
}
