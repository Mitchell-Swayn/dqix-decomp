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
extern "C" ZoneTintState* func_0200fd0c(GameState*);
extern "C" void func_0207df90(void*);
extern "C" void func_0207dfac(void*);
extern "C" void func_020e2fc0(RenderCommandHandler*);



bool Zone3D::LoadBMDJModel(Zone3D_BMDJStruct* group, Zone3D_BMDJStruct::ObjectEntry* entry, Zone3D_BMDJStruct::StructSizeC* definition)
{
    GameState* game = GameState::GetInstance();
    void* textureContext = unknown_ptr_50_;
    SafeAllocator* allocator = pAllocator_68_;
    LightingManager* lightingManager = LightingManager::GetInstance();
    int timeOfDay = lightingManager->timeOfDayIndex_;
    Model3DListNode* alternate = NULL;
    bool tint = func_0200fd0c(game)->unknown_20 < 0;
    unknown_834_ = tint;
    for (Zone3D_BMDJStruct::StructSizeC* variant = definition->pNext; variant; variant = variant->pNext)
    {
        if (variant->maybeID == timeOfDay)
        {
            definition = variant;
            break;
        }
    }
    char path[80];
    unsigned int length;
    BuildArcMemberPath(definition->name, gZone3DPaths.modelExtension, path);
    const void* raw = GetFileFromNARCInMemory(path);
    if (raw)
    {
        entry->model = (Model3D*)allocator->Allocate(sizeof(Model3D));
        void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*allocator, raw, length);
        if (decompressed && entry->model)
        {
            entry->model->Clear();
            func_0207df90(textureContext);
            entry->model->SetAndProcessRawFile(decompressed, length, Model3D::TextureStagingMode_Normal);
            func_0207dfac(textureContext);
            NSBXXTex* texture = entry->model->GetTEX0();
            if (texture)
            {
                textureImageMemory_ += NSBXX_Tex_GetBlock1Length(texture);
                texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(texture);
            }
            ModelRenderContext* context = entry->model->unknown_flags_a8_0_ ? &entry->model->renderContext_ : NULL;
            if (context)
                SetModelRenderContextRenderCommandHook(context, func_020e2fc0, 0, 8, 1);
            if (!(definition->unk_2 & 0x20) && tint)
                lightingManager->ModelTransformTintBrightnessContrast(entry->model->rawInternalModel_);
            for (Model3DListNode* donor = firstModel_418_; donor; donor = donor->pNext_)
            {
                entry->model->ApplyTexturesFromModel(&donor->model_);
                entry->model->SetTEX0(donor->model_.GetTEX0());
            }
            Model3DListNode* first = firstModel_418_;
            const char* name;
            for (int i = 0; i < 8; ++i)
            {
                if (definition->unk_3 & (1 << i))
                {
                    name = group->scriptData_.GetString(i);
                    if (name)
                    {
                        for (alternate = first; alternate; alternate = alternate->pNext_)
                            if (strstr(alternate->filename_, name))
                                goto found;
                    }
                }
            }
            alternate = NULL;
found:
            int flags = 0;
            if (!(definition->unk_2 & 1)) flags |= 1;
            if (flags) entry->model->CreateBoneMatrixAndMaterialArrays(allocator, flags);
        }
        if (!entry->model)
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
    if (entry->model)
    {
        ModelAnimationRules rules = data_020e6fa8;
        rules.rules[0].destination = &entry->skeletalAnimation;
        rules.rules[1].destination = &entry->materialAnimation;
        rules.rules[2].destination = &entry->textureAnimation;
        rules.rules[3].destination = &entry->patternAnimation;
        for (ModelAnimationRule* rule = rules.rules; rule->mask; ++rule)
        {
            if (!(rule->mask & definition->unk_2)) continue;
            BuildArcMemberPath(definition->name, rule->extension, path);
            const void* animationFile = GetFileFromNARCInMemory(path);
            if (!animationFile) continue;
            Animation3D* animation = (Animation3D*)allocator->Allocate(sizeof(Animation3D));
            void* animationData = DecompressLZ77FileIntoAllocatedSpace(*allocator, animationFile, length);
            if (!animationData || !animation) continue;
            animation->DefaultInitialize();
            animation->SetRawFile((NSBXXContainer*)animationData);
            if (alternate)
            {
                animation->CreateData(entry->model, allocator, &alternate->model_);
                entry->model->AddAnimation(animation);
                *rule->destination = animation;
            }
            else
            {
                animation->CreateData(entry->model, allocator, NULL);
                entry->model->AddAnimation(animation);
                *rule->destination = animation;
            }
        }
    }
    entry->kind = 0;
    return true;
}
