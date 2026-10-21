#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Filesystem/BackgroundLoader.h>
#include <GameState/GameState.h>
#include <System/Matrix.h>
struct PitState { unsigned char phase, flag; unsigned short timer; int task; unsigned effect; unsigned char strings[8]; SafeAllocator allocator; };
struct LowNibble { unsigned char value:4,rest:4; };
struct MiddleNibble { unsigned char low:2,value:4,high:2; };
struct MetadataBit { unsigned char low:6,value:1,high:1; };
struct LowByte { unsigned low:8,rest:24; };
struct PitRecord { unsigned short key; unsigned char unknown[6]; unsigned char* metadata; };
struct PitSelection { unsigned char unknown[12]; unsigned char member; };
struct TextDisplay { void* geometry; unsigned char unknown[0x994]; int busy; };
struct PackedPosition { short x,y,z; };
struct EffectFlags { unsigned char a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1; };
struct EffectDescriptor { unsigned char kind; unsigned char pad[15]; unsigned char enabled; EffectFlags flags; unsigned short value; short fields[5]; unsigned short pad2; unsigned words[3]; Vector3i position; unsigned words2[3]; Vector3i scale; };
extern "C" {
TextDisplay* TextContext_GetSharedInstance();
int GameState_ReadFirstObjectIndex(GameState*); int GameState_ReadProtagonistObjectIndex(GameState*);
void* Network_GetConnectionManager(); PitRecord* Zone3D_GetMainInstance();
void GameObject_DisableMovementInput(GameObject*,int); void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
void Pitfall_ReleasePlacementSequence(PitState*);
void MessageTextTable_Reset(void*); void Script_ExecuteCodeWithGlobalContextValues(void*,SafeAllocator*,void*,unsigned,int,int,int);
GameObject* GameObject_GetFloorContactDescriptor(GameObject*); void* GameState_GetFieldAddress468(GameState*); int GameState_DecodePackedDecimalIdentifier(GameObject*); unsigned char* ZoneTable_FindEntryById(void*,int);
unsigned short* GameState_GetPendingPartyPositionRecord(GameState*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int); void* MessageTextTable_FindTextById(void*,int);
void GameState_BuildTwelveByteDescriptorForPartyMember(void*,int); void TextLayout_ResetFormattingWorkspace(TextDisplay*); void TextWindow_StartFormattedMessage(TextDisplay*,void*,int,int); int TextWindow_GetChoiceResult(TextDisplay*);
void SoundSfx_LoadGroupAtCurrentHeapState(void*,int,int); void ResourceHandle_InvokeOperationWithValidHalfwordIndex(void*,int,int); void SoundSfx_RestoreHeapAfterGroupPlayback(void*);
void TextureVRAM_SnapshotAllocationBounds(void*); void Graphics_RestoreTextureImageAndPaletteVRAMState(void*); void Object_InvokeSaveTextureImageVRAMState(void*);
void* Object_GetGlobalSixteenEntryDisplayState(); int Object_AllocateAndAppendInitializedLinkedNode(void*,int,SafeAllocator*,void*,unsigned); unsigned ObjectPool_SpawnFromTemplateKey(void*,int,EffectDescriptor*);
int Network_IsParentOrOffline(void*); void* ActionData_GetGlobalTables(); void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int); void Object_SubtractAmountWithConditionalScaling(GameObject*,unsigned); void GameObject_DeferPositionMatch(GameObject*);
void Network_QueueTypeB6PackedPosition(int,unsigned,unsigned short,PackedPosition);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[], Main_UnknownRoleZeroInitializedStorage[];
extern char Pitfall_AdvancePlacementSequence_PathDataBinStrPitGp2[],Pitfall_AdvancePlacementSequence_MarkupStrPitLGBin[],Pitfall_AdvancePlacementSequence_PathDataEffectAnaChr[];
}
// Original: arm9/ov010 @ 0x02184354; symbol: func_ov010_02184354; size: 0x718.
extern "C" int Pitfall_AdvancePlacementSequence(PitState* state) {
    BackgroundLoader* loader;
    TextDisplay* display;
    GameState* game;
    GameObject* member;
    PitRecord* record;
    PitSelection* selection;
    GameObject* leader;
    loader = BackgroundLoader::GetInstance();
    display = TextContext_GetSharedInstance();
    game = GameState::GetInstance();
    selection = *(PitSelection**)((unsigned char*)GameResources_GetInstance()+0x3ba8);
    member = game->GetPartyMemberByIndex(selection->member);
    int leaderIndex = GameState_ReadFirstObjectIndex(game);
    leader = game->GetPartyMemberByIndex(leaderIndex);
    void* world = Network_GetConnectionManager();
    unsigned char* field = (unsigned char*)GameResources_GetInstance();
    record = Zone3D_GetMainInstance();
    if (!member || !leader) { Pitfall_ReleasePlacementSequence(state); return 1; }
    if (state->phase == 0) {
        GameObject_DisableMovementInput(leader,1);
        void* buffer = AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,0x7800);
        if (!buffer) { Pitfall_ReleasePlacementSequence(state); return 1; }
        state->allocator.CreateTypeA(buffer,0x7800);
        state->task = loader->QueueLoadFileInGP2(Pitfall_AdvancePlacementSequence_PathDataBinStrPitGp2,Pitfall_AdvancePlacementSequence_MarkupStrPitLGBin,0);
        state->phase = 1;
    } else if (state->phase == 1) {
        if (!loader->GetTaskStatus(state->task)) return 0;
        if (loader->GetDetailedTaskStatus(state->task)!=2) { Pitfall_ReleasePlacementSequence(state); return 1; }
        void* stringData; unsigned stringSize;
        loader->GetLoadedFileByID(state->task,&stringData,&stringSize);
        MessageTextTable_Reset(state->strings);
        Script_ExecuteCodeWithGlobalContextValues(state->strings,&state->allocator,stringData,stringSize,0,0,0);
        loader->RemoveTask(state->task);
        unsigned short* location = GameState_GetPendingPartyPositionRecord(game,GameState_ReadProtagonistObjectIndex(game));
        if (!location) { Pitfall_ReleasePlacementSequence(state); return 1; }
        unsigned char* metadata = record->metadata;
        if (!metadata) { Pitfall_ReleasePlacementSequence(state); return 1; }
        unsigned enabled=1;
        state->flag = enabled;
        if (((LowNibble*)(metadata+12))->value==0) {
            member = GameObject_GetFloorContactDescriptor(member);
            if (member) {
                void* progress = GameState_GetFieldAddress468(game);
                int key = GameState_DecodePackedDecimalIdentifier(member);
                unsigned char* entry = ZoneTable_FindEntryById(progress,key);
                if (entry && ((MiddleNibble*)(entry+14))->value) state->flag=0;
            }
        } else { metadata=record->metadata; if (metadata) { if (!((MetadataBit*)(metadata+14))->value) enabled=0; state->flag=enabled; } }
        int text;
        if (!state->flag) { state->phase=3; text=2; }
        else if (*location) { state->phase=2; text=1; }
        else { text=0; state->phase=4; SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,100,0); }
        void* message = MessageTextTable_FindTextById(state->strings,(short)text);
        unsigned geometry[3]; GameState_BuildTwelveByteDescriptorForPartyMember(geometry,selection->member);
        TextLayout_ResetFormattingWorkspace(display); display->geometry=geometry;
        TextWindow_StartFormattedMessage(display,message,0,227); display->busy=1;
    } else if (state->phase == 2) {
        if (display->busy) return 0;
        if (!TextWindow_GetChoiceResult(display)) {
        void* message = MessageTextTable_FindTextById(state->strings,0);
        unsigned geometry[3]; GameState_BuildTwelveByteDescriptorForPartyMember(geometry,selection->member);
        TextLayout_ResetFormattingWorkspace(display); display->geometry=geometry;
        TextWindow_StartFormattedMessage(display,message,0,227); display->busy=1;
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,100,0);
        unsigned short* location = GameState_GetPendingPartyPositionRecord(game,GameState_ReadProtagonistObjectIndex(game));
        if (location) *location=0;
        state->phase=4;
        } else { Pitfall_ReleasePlacementSequence(state); return 1; }
    } else if (state->phase == 4) {
        state->task=loader->QueueLoadFile(Pitfall_AdvancePlacementSequence_PathDataEffectAnaChr,0);
        state->phase=5; state->timer=0;
    } else if (state->phase == 5) {
        if (!loader->GetTaskStatus(state->task)) return 0;
        if (loader->GetDetailedTaskStatus(state->task)!=2) { Pitfall_ReleasePlacementSequence(state); return 1; }
        if (state->timer < 15) { ++state->timer; return 0; }
        SoundSfx_LoadGroupAtCurrentHeapState(Main_UnknownRoleZeroInitializedStorage,116,116); ResourceHandle_InvokeOperationWithValidHalfwordIndex(Main_UnknownRoleZeroInitializedStorage,0,0);
        void* effectData; unsigned effectSize;
        loader->GetLoadedFileByID(state->task,&effectData,&effectSize);
        unsigned char* transform = field+0x2cc;
        Vector3i position=*(Vector3i*)((unsigned char*)member+0x44);
        TextureVRAM_SnapshotAllocationBounds(transform+0xc40); Graphics_RestoreTextureImageAndPaletteVRAMState(transform+0xc40);
        void* effects = Object_GetGlobalSixteenEntryDisplayState();
        Object_AllocateAndAppendInitializedLinkedNode(effects,17,&state->allocator,effectData,effectSize);
        Object_InvokeSaveTextureImageVRAMState(transform+0xc40);
        EffectDescriptor descriptor;
        descriptor.kind=0; descriptor.value=0;
        descriptor.words[0]=0; descriptor.words[1]=0; descriptor.words[2]=0;
        descriptor.position.x=0; descriptor.position.y=0; descriptor.position.z=0;
        descriptor.words2[0]=0; descriptor.words2[1]=0; descriptor.words2[2]=0;
        descriptor.fields[4]=-4096; descriptor.enabled=1;
        descriptor.fields[0]=-1; descriptor.fields[1]=-1; descriptor.fields[2]=-1; descriptor.fields[3]=-1;
        descriptor.scale.x=4096; descriptor.scale.y=4096; descriptor.scale.z=4096;
        Vector3i scale; scale.x=266; scale.y=266; scale.z=266;
        descriptor.flags.a=0; descriptor.flags.b=0; descriptor.flags.c=1; descriptor.flags.d=0;
        descriptor.flags.e=0; descriptor.flags.f=0; descriptor.flags.g=0; descriptor.flags.h=0;
        descriptor.position=position; descriptor.scale=scale;
        state->effect=ObjectPool_SpawnFromTemplateKey(effects,17,&descriptor);
        PackedPosition packed; packed.x=position.x>>4; packed.y=position.y>>4; packed.z=position.z>>4;
        if (Network_IsParentOrOffline(world)) {
            unsigned short* location = GameState_GetPendingPartyPositionRecord(game,GameState_ReadProtagonistObjectIndex(game));
            if (location) { location[0]=record->key; location[1]=packed.x; location[2]=packed.y; location[3]=packed.z; }
        }
        unsigned* entry = (unsigned*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(),210);
        if (entry) Object_SubtractAmountWithConditionalScaling(member,((LowByte*)(entry+2))->low);
        GameObject* active=game->GetUnknownGameObject(); if (active) GameObject_DeferPositionMatch(active);
        int index=GameState_ReadProtagonistObjectIndex(game);
        Network_QueueTypeB6PackedPosition(0,(unsigned char)index,record->key,packed);
        state->phase=3;
    } else if (state->phase == 3) {
        GameState* current=GameState::GetInstance();
        int done=0;
        if (state->flag) { if (!current->GetGameObjectByIndex(state->effect) && !display->busy) done=1; }
        else { if (!display->busy) done=1; }
        if (done) { Pitfall_ReleasePlacementSequence(state); SoundSfx_RestoreHeapAfterGroupPlayback(Main_UnknownRoleZeroInitializedStorage); return 1; }
    }
    return 0;
}
