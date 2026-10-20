#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#pragma force_active on
ARM
struct Owner;
struct MappingWord { int value; int adjacent; };
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" void GameState_BuildEquipmentObjectIdsAndDefaultValues(int,int*,short*);
extern "C" void CharacterState_InitializeEquipmentDescriptors(void*);
extern "C" void ZoneState2754_UpdateRecordsForKeysFromSerializedData(int,int,int,int,short);
extern "C" void GameObject_SetLinkedStatAndMarkChanged(Owner*,int,int);
// Original data: arm9/ov017 @ 0x021D6B74; symbol: data_ov017_021d6b74.
// First words of an eight-byte-stride mapping from linked-stat indices to descriptor indices.
extern "C" const int FieldAppearanceApplyLoadedEquipmentDescriptors_UnknownRoleInitializedBytes[];
// Original data: arm9/ov017 @ 0x021D6B78; symbol: data_ov017_021d6b78.
// Second words of the same mapping, ending with a negative first-word sentinel.
extern "C" const int FieldAppearance_ApplyLoadedEquipmentDescriptors_SentinelTerminatedIndexList[21];
// Original: arm9/ov017 @ 0x021B3560; symbol: func_ov017_021b3560; size: 0x118.
// Applies loaded equipment descriptors and marks linked stats whose equipment keys changed.
extern "C" int FieldAppearance_ApplyLoadedEquipmentDescriptors(unsigned char* request)
{
    GameState* game=GameState::GetInstance();
    BackgroundLoader* loader=BackgroundLoader::GetInstance();
    if(!loader->GetTaskStatus(*(int*)(request+0x10))) return 0;
    GameObject* object=GameState_GetObjectWithFlag100(game,*(short*)(request+8));
    if(!object) return 0;
    unsigned char* state=(unsigned char*)GameObject_GetLinkedIndexedState((int)object);
    if(!state) return 0;
    int ids[11];
    short values[11];
    GameState_BuildEquipmentObjectIdsAndDefaultValues(*(short*)(request+8),ids,values);
    void* data;
    unsigned length;
    loader->GetLoadedFileByID(*(int*)(request+0x10),&data,&length);
    CharacterState_InitializeEquipmentDescriptors(state);
    ZoneState2754_UpdateRecordsForKeysFromSerializedData((int)(state+0x194),(int)data,length,(int)values,11);
    loader->RemoveTask(*(int*)(request+0x10));
    *(int*)(request+0x10)=-1;
    for(int i=0;((const MappingWord*)FieldAppearanceApplyLoadedEquipmentDescriptors_UnknownRoleInitializedBytes)[i].value>=0;++i) {
        int stat=((const MappingWord*)FieldAppearanceApplyLoadedEquipmentDescriptors_UnknownRoleInitializedBytes)[i].value;
        int descriptor=((const MappingWord*)FieldAppearance_ApplyLoadedEquipmentDescriptors_SentinelTerminatedIndexList)[i].value;
        if(*(short*)(state+0x1ac+descriptor*0x20)!=values[descriptor]) GameObject_SetLinkedStatAndMarkChanged((Owner*)object,stat,-1);
    }
    return 1;
}
