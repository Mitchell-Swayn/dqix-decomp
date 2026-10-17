#pragma opt_propagation off
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"
struct NameTable;
struct NameRecord { unsigned short id; unsigned char reserved[3]; char name[1]; };
struct ModelLoadLocks;
struct FieldEffect {
    Object3D model;
    short reservedAC, heading;
    unsigned short id, reservedB2, valueB4, valueB6;
    char reservedB8[0xe0 - 0xb8];
    unsigned char flagsE0;
    char reservedE1[0x144 - 0xe1];
    Vector3i priorPosition;
    char reserved150[0x170 - 0x150];
};
struct EffectResourceState { SafeAllocator* allocator; ModelLoadLocks* locks; };
extern "C" const char data_020f1b50[], data_020f1b52[];
extern "C" EffectResourceState data_ov017_021d82fc;
extern "C" NameTable* GameState_GetFieldAddress468(GameState*);
extern "C" NameRecord* Object_FindRecordByKeyInCountedArray(NameTable*, int);
extern "C" GameObject* ReadSignedWordField32C(GameState*);
extern "C" void GameState_SetIndexedObjectAndSlot(GameState*, int, Object3D*);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(ModelLoadLocks*);
extern "C" void Object_InvokeSaveTextureImageVRAMState(ModelLoadLocks*);
extern "C" Zone3D* ReadGlobalValueAt020FB3F0();
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(Object3D*, int);
extern "C" void ClearMaskedFlagsAtOffsetE0(Object3D*);
extern "C" void InitializeObjectFlag8000AndResourceFields(FieldEffect*);
extern "C" void RemoveThreeResourcesAndResetFourTasks(EffectResourceState*);
extern "C" void func_020a72ac(Zone3D*, int);
inline Vector3i* GetEffectOrigin(Zone3D* zone) { return &zone->unknown_2774_; }
// Original: arm9/main @ 0x020A6728; symbol: func_020a6728; size: 0x244.
extern "C" void TestZoneAndResolvedNameConditions(char* owner, int id)
{
    GameState* game = GameState::GetInstance();
    NameRecord* record = Object_FindRecordByKeyInCountedArray(GameState_GetFieldAddress468(game), id);
    char* name = 0;
    if (record) name = record->name;
    if (id == 10000 || id == 10100 ||
        (id >= 20000 && id <= 29999 && name && !strstr(name, data_020f1b50))) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        SafeAllocator* allocator = (SafeAllocator*)(owner + 0xc4);
        char* subState = owner + 0x2cc;
        ModelLoadLocks* locks = (ModelLoadLocks*)(subState + 0x310);
        ReadSignedWordField32C(game);
        unsigned int length;
        if (loader->GetNumQueuedTasks() <= 0) {
            void* archive = LoadFileIntoNewAllocation(data_020f1b52, *allocator, &length);
            if (archive) {
                FieldEffect* effect = (FieldEffect*)allocator->Allocate(0x170);
                if (effect) {
                    InitializeObjectFlag8000AndResourceFields(effect);
                    ObjectArchiveLoadInfo info;
                    info.unk_0 = 0; info.fileData = 0; info.unk_8 = 0; info.allocator = 0;
                    info.unk_10 = 0; info.unk_14 = 0; info.unk_18 = 0; info.packageID = 0;
                    Graphics_RestoreTextureImageAndPaletteVRAMState(locks);
                    info.unk_8 = length;
                    info.fileData = archive;
                    info.allocator = allocator;
                    effect->model.LoadFromCHRArchive(&info);
                    Object_InvokeSaveTextureImageVRAMState(locks);
                    Zone3D* zone = ReadGlobalValueAt020FB3F0();
                    game->GetUnknownGameObject();
                    effect->model.position_ = *GetEffectOrigin(zone);
                    effect->priorPosition = *GetEffectOrigin(zone);
                    effect->model.SetScale(160, 160, 160);
                    Object3D_SetNormalizedAngleAndUpdatePosition(&effect->model, zone->unknown_2780_);
                    effect->id = 201;
                    effect->valueB4 = 262;
                    effect->valueB6 = 10;
                    effect->model.MakeVisible();
                    ClearMaskedFlagsAtOffsetE0(&effect->model);
                    effect->flagsE0 &= ~1;
                    effect->model.DisableFlag(0x180);
                    effect->model.EnableFlag(0x400000);
                    GameState_SetIndexedObjectAndSlot(game, 201, &effect->model);
                    if (id == 10000) {
                        SafeAllocator* newAllocator = (SafeAllocator*)allocator->Allocate(20);
                        newAllocator->ResetAllocatorPointer();
                        void* region = allocator->Allocate(0x3c00);
                        newAllocator->CreateTypeA(region, 0x3c00);
                        RemoveThreeResourcesAndResetFourTasks(&data_ov017_021d82fc);
                        data_ov017_021d82fc.allocator = newAllocator;
                        data_ov017_021d82fc.locks = locks;
                    }
                    func_020a72ac(ReadGlobalValueAt020FB3F0(), 0);
                }
            }
        }
    }
}
