#include "World/Zone3D.h"
#include "World/BMDJAnimationRules.h"
#include "World/Zone3DPaths.h"
#include "World/MapArchive.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"

struct ZoneTintState
{
    char unknown_0[0x20];
    int unknown_20;
};
extern "C" ZoneTintState* GameState_ReadUnkF8(GameState*);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
extern "C" void Object_InvokeSaveTextureImageVRAMState(void*);



// Original: arm9/main @ 0x020151CC; symbol: _ZN6Zone3D22LoadBMDJAnimatedObjectEPN17Zone3D_BMDJStruct11ObjectEntryEPNS0_11StructSizeCE; size: 0x26C.
bool Zone3D::LoadBMDJAnimatedObject(Zone3D_BMDJStruct::ObjectEntry* entry, Zone3D_BMDJStruct::StructSizeC* definition)
{
    GameState* game = GameState::GetInstance();
    SafeAllocator* allocator = pAllocator_68_;
    void* textureContext = unknown_ptr_50_;
    LightingManager* lightingManager = LightingManager::GetInstance();
    bool tint = GameState_ReadUnkF8(game)->unknown_20 < 0;
    unknown_834_ = tint;
    char path[80];
    unsigned int length;
    BuildArcMemberPath(definition->name, gZone3DPaths.modelExtension, path);
    const void* raw = GetFileFromNARCInMemory(path);
    Object3D* object;
    if (raw)
    {
        entry->object = (Object3D*)allocator->Allocate(sizeof(Object3D));
        void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*allocator, raw, length);
        if (decompressed && entry->object)
        {
            entry->object->Initialize();
            Graphics_RestoreTextureImageAndPaletteVRAMState(textureContext);
            entry->object->SetModelFromFile(allocator, decompressed, length, Model3D::TextureStagingMode_Normal);
            Object_InvokeSaveTextureImageVRAMState(textureContext);
            Model3D* model = entry->object->pModel_;
            if (model)
            {
                NSBXXTex* texture = model->GetTEX0();
                if (texture)
                {
                    textureImageMemory_ += NSBXX_Tex_GetBlock1Length(texture);
                    texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(texture);
                }
                if (!(definition->unk_2 & 0x20) && tint)
                    lightingManager->ModelTransformTintBrightnessContrast(model->rawInternalModel_);
                for (Model3DListNode* donor = firstModel_418_; donor; donor = donor->pNext_)
                {
                    model->ApplyTexturesFromModel(&donor->model_);
                    model->SetTEX0(donor->model_.GetTEX0());
                }
            }
        }
        object = entry->object;
        if (!object || !object->pModel_)
        {
            entry->kind = -1;
            return false;
        }
    }
    else
    {
        entry->kind = -1;
        return false;
    }
    if (object)
    {
        ObjectAnimationRules rules = data_020e6f48;
        for (ObjectAnimationRule* rule = rules.rules; rule->mask; ++rule)
        {
            if (!(rule->mask & definition->unk_2)) continue;
            BuildArcMemberPath(definition->name, rule->extension, path);
            const void* animation = GetFileFromNARCInMemory(path);
            if (!animation) continue;
            void* animationData = DecompressLZ77FileIntoAllocatedSpace(*allocator, animation, length);
            if (!animationData) continue;
            if (rule->slot < 0)
                object->LoadType0AnimationPackageFromBCFGScript(allocator, animationData, length);
            else
                object->LoadType0AnimationFromPersistentMemory(rule->slot, allocator, animationData, length);
        }
    }
    entry->kind = 2;
    return true;
}
