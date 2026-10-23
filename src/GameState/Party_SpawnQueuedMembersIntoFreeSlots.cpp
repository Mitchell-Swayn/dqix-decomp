#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
ARM
typedef unsigned char undefined1;typedef unsigned undefined4;
struct E;struct Character;struct Input;
extern "C" {
 void* GameState_GetIndexList(GameState*);
 void* Zone3D_GetMainInstance();
 int PartyRoster_GetFirstPendingRecruitSlotId(char*);
 E* PartyRoster_FindCharacterBySlotId(char*,int);
 GameStateIndexedRecord* GameState_FindCharacterStateByObjectIndex(GameState*,int);
 GameStateIndexedRecord* GameState_FindUnusedIndexedRecord(GameState*);
 void CharacterState_ResetAuxiliaryTrackingAndResourceCodes(char*);
 void CharacterState_InitializeFromSerializedRecord(Character*,const Input*);
 void Field_CreatePartyObjectAndEquipmentSlots(GameResources*,int,unsigned,int,int);
 GameObject* GameState_FindIndexedObjectWithFlag1000(GameState*,int);
 void CopyMatchedRecordToPartyMemberAndClearSource(void*,int,int);
 int GameState_ReadProtagonistObjectIndex(GameState*);
 void GameObject_SetAssociatedPartyMemberIndex(int,int);
 int GameObject_GetAssociatedPartyMemberIndex(int);
 void GameObject_SetSecondaryPartyMemberIndex(int,int);
 unsigned GameObject_GetLinkedIndexedState(int);
 void* __clear(void*,unsigned);
 void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
 unsigned PartyRecord_GetSelectedVocation(int);
 void CharacterState_SelectAndUnlockVocation(char*,unsigned);
 void Field_RebuildActiveRosterAndCameraTarget(int,int,int,int,int);
 void PartyRoster_RemoveCharacterBySlotIdAndCompact(void*,int);
}
// Original: arm9/main @ 0x020DCD40; symbol: Party_SpawnQueuedMembersIntoFreeSlots; size: 0x23C.
extern "C" int Party_SpawnQueuedMembersIntoFreeSlots(){
 int spawned=0;
 GameResources* resources=GameResources_GetInstance();GameState* game=GameState::GetInstance();char* roster=(char*)GameState_GetIndexList(game);unsigned short* zone=(unsigned short*)Zone3D_GetMainInstance();
 for(;;){int pending=PartyRoster_GetFirstPendingRecruitSlotId(roster);if(pending<0)break;E* record=PartyRoster_FindCharacterBySlotId(roster,pending);if(!record)break;
 int index=-1;for(int i=3;i>=0;--i){if(!game->GetGameObjectByIndex(i)){index=i;break;}}if(index<0)break;
 GameStateIndexedRecord* state=GameState_FindCharacterStateByObjectIndex(game,index);if(!state)state=GameState_FindUnusedIndexedRecord(game);state->objectIndex_=index;
 CharacterState_ResetAuxiliaryTrackingAndResourceCodes((char*)state);CharacterState_InitializeFromSerializedRecord((Character*)state,(Input*)record);
 Field_CreatePartyObjectAndEquipmentSlots(resources,index,0x1000,1,0);
 GameObject* object=GameState_FindIndexedObjectWithFlag1000(game,index);if(!object)break;
 void* transferRoster=GameState_GetIndexList(game);CopyMatchedRecordToPartyMemberAndClearSource(transferRoster,pending,(signed char)index);
 object->obj3D_.SetField06(*zone);game->GetProtagonist();int leader=GameState_ReadProtagonistObjectIndex(game);GameObject_SetAssociatedPartyMemberIndex((int)object,leader);
 int followers=0;for(int i=0;i<4;++i){GameObject* other=GameState_FindIndexedObjectWithFlag1000(game,i);if(other&&i!=index){if(leader==GameObject_GetAssociatedPartyMemberIndex((int)other))++followers;}}
 GameObject_SetSecondaryPartyMemberIndex((int)object,followers);GameState_GetIndexList(game);char* linked=(char*)GameObject_GetLinkedIndexedState((int)object);
 unsigned char name[48];__clear(name,48);Text_MapInputBytesToVariableLengthOutputSequences((unsigned char*)record+0x140,name,1);strcpy(*(char**)((char*)object+0x134),(char*)name);
 unsigned vocation=PartyRecord_GetSelectedVocation((int)record);*(unsigned short*)(linked+0x16c+vocation*2)=*((unsigned char*)record+2+PartyRecord_GetSelectedVocation((int)record));CharacterState_SelectAndUnlockVocation(linked,PartyRecord_GetSelectedVocation((int)record));
 Field_RebuildActiveRosterAndCameraTarget((int)resources,1,1,1,1);PartyRoster_RemoveCharacterBySlotIdAndCompact(transferRoster,pending);++spawned;
 }return spawned;
}
