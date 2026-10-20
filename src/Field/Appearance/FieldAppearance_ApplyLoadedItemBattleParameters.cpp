#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#pragma force_active on
ARM
struct Header { unsigned count:12; unsigned rest:19; unsigned owned:1; unsigned char *first,*second; };
struct ItemBattleParameters { unsigned words[10]; short key; short reserved; };
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" void* ScriptRecordTable_ResetView(void*);
extern "C" void ScriptRecordTable_AttachSerializedView(Header*,Header*,unsigned);
extern "C" void* ScriptRecordTable_FindEntryBySignedKey(Header*,int);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void CharacterState_RecalculateOrPreviewDerivedStats(void*,int);
// Original data: arm9/ov017 @ 0x021D6B20; symbol: data_ov017_021d6b20.
extern "C" const unsigned char FieldAppearanceApplyLoadedItemBattleParameters_UnknownRoleInitializedBytes[];
// Original: arm9/ov017 @ 0x021B3780; symbol: func_ov017_021b3780; size: 0x148.
// Loads eight item battle parameter records using equipment descriptor keys.
extern "C" int FieldAppearance_ApplyLoadedItemBattleParameters(unsigned char* request)
{
    GameState* game=GameState::GetInstance();
    BackgroundLoader* loader=BackgroundLoader::GetInstance();
    if(!loader->GetTaskStatus(*(int*)(request+0x10))) return 0;
    GameObject* object=GameState_GetObjectWithFlag100(game,*(short*)(request+8));
    if(!object) return 0;
    unsigned char* state=(unsigned char*)GameObject_GetLinkedIndexedState((int)object);
    if(!state) return 0;
    int task=*(int*)(request+0x10);
    void* data;
    unsigned length;
    loader->GetLoadedFileByID(task,&data,&length);
    Header view;
    ScriptRecordTable_ResetView(&view);
    ScriptRecordTable_AttachSerializedView(&view,(Header*)data,length);
    ItemBattleParameters* output=(ItemBattleParameters*)(*(unsigned char**)((unsigned char*)object+0x150)+0x2f4);
    const unsigned char* mapping=FieldAppearanceApplyLoadedItemBattleParameters_UnknownRoleInitializedBytes;
    for(int i=0;i<8;++i,++mapping,++output) {
        output->words[0]=0;output->words[1]=0;output->words[2]=0;output->words[3]=0;output->words[4]=0;
        output->words[5]=0;output->words[6]=0;output->words[7]=0;output->words[8]=0;output->words[9]=0;
        output->key=-1;
        int key=*(short*)(state+0x1ac+*mapping*0x20);
        if(key>0) {
            void* entry=ScriptRecordTable_FindEntryBySignedKey(&view,key);
            if(entry) memcpy(output,entry,44);
        }
    }
    loader->RemoveTask(task);
    *(int*)(request+0x10)=-1;
    CharacterState_RecalculateOrPreviewDerivedStats(state,0);
    return 1;
}
