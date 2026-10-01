#include "World/Zone3D.h"
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
extern "C" ZoneTintState* func_0200fd0c(GameState*);
extern "C" void func_0207df90(void*);
extern "C" void func_0207dfac(void*);

struct ObjectAnimationRule
{
    unsigned int mask;
    int slot;
    char extension[8];
};
struct ObjectAnimationRules
{
    ObjectAnimationRule rules[6];
};
extern const ObjectAnimationRules data_020e6f48 =
{{
    { 1, 0, "nsbca" },
    { 2, 1, "nsbma" },
    { 4, 3, "nsbta" },
    { 8, 2, "nsbtp" },
    { 16, -1, "bcfg" },
    { 0, 0, "" }
}};

bool Zone3D::LoadBMDJAnimatedObject(Zone3D_BMDJStruct::ObjectEntry* entry, Zone3D_BMDJStruct::StructSizeC* definition)
{
    GameState* game = GameState::GetInstance();
    SafeAllocator* allocator = pAllocator_68_;
    void* textureContext = unknown_ptr_50_;
    LightingManager* lightingManager = LightingManager::GetInstance();
    bool tint = func_0200fd0c(game)->unknown_20 < 0;
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
            func_0207df90(textureContext);
            entry->object->SetModelFromFile(allocator, decompressed, length, Model3D::TextureStagingMode_Normal);
            func_0207dfac(textureContext);
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
            entry->id = -1;
            return false;
        }
    }
    else
    {
        entry->id = -1;
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
    entry->id = 2;
    return true;
}
