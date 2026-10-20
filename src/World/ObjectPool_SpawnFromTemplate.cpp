#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/NSBXX/Animation.h"
#pragma thumb off
#pragma opt_common_subs off
struct ResourceInstance {
    unsigned char reserved00[8];
    int parameter;
    unsigned char enabled;
    unsigned char reserved0D[0x2c];
    unsigned char option39, option3A, option3B;
    unsigned char reserved3C[0xac];
    Matrix4x3 transform;
};
struct ResourceBinding {
    void* resourceC;
    ResourceInstance* instance;
    Object3D* object;
    void* resourceA;
    unsigned reserved[3];
};
struct PoolSlot {
    union { Object3D object; ResourceBinding binding; } content;
    int alternateRepresentation;
    short valueB0, valueB2, valueB4, valueB6;
    int valueB8, valueBC;
    Vector3fix vectorC0;
    unsigned char reservedFlag : 1;
    unsigned char sourceFlag0 : 1;
    unsigned char sourceFlag2 : 1;
    unsigned char sourceFlag1 : 1;
    unsigned char sourceFlag6 : 1;
    unsigned char sourceFlag7 : 1;
    unsigned char reservedFlags : 2;
    unsigned char reservedCD[3];
    int templateKey;
};
struct ObjectPool { unsigned reserved[2]; PoolSlot slots[16]; };
struct ObjectTemplate {
    int key;
    void* resourceC;
    unsigned char reserved08[0xc];
    Object3D object;
    unsigned char resourceDescriptor[0x128];
    int alternateRepresentation;
};
struct SpawnParameters {
    char animation[16];
    unsigned char animationFlags;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 1;
    unsigned char flag5 : 1;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
    short value12, value14, value16, value18, value1A, value1C;
    unsigned short reserved1E;
    Vector3fix vector20, position, rotation, scale;
};
typedef char PoolSlotSizeCheck[sizeof(PoolSlot)==0xd4?1:-1];
typedef char ObjectTemplateSizeCheck[sizeof(ObjectTemplate)==0x1ec?1:-1];
extern "C" {
void GameState_SetIndexedObjectAndSlot(GameState*,int,GameObject*);
void ResourceTracks_ClearBindingOwner(ResourceBinding*);
int ResourceTracks_BindResourcesAndInitializePlayback(ResourceBinding*,void*,Object3D*,void*);
void Graphics_SubmitScaledBillboardMatrix(RenderCommandHandler*);
extern const char ObjectPool_SpawnFromTemplate_TextZure[];
// Original data: arm9/main @ 0x20e7d84; symbol: data_020e7d84.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a0100000a0100000a010000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const Vector3fix ObjectPoolSpawnFromTemplate_UnknownRoleInitializedBytes;
}
ModelRenderContext* GetModel3DContext(Model3D*);
// Original: arm9/main @ 0x02057FD8; symbol: func_02057fd8; size: 0x58C.
// Reserve a free GameState object slot and instantiate either a cloned model
// or a bound resource instance, carrying the shared spawn parameters into it.
extern "C" int ObjectPool_SpawnFromTemplate(ObjectPool* pool, ObjectTemplate* source, SpawnParameters* params)
{
    GameState* state = GameState::GetInstance();
    if (!source) return -1;
    if (!params) return -1;
    int objectIndex = -1;
    int slotIndex = 0;
    for (; slotIndex < 16; ++slotIndex) {
        if (!state->GetGameObjectByIndex(slotIndex+208)) {
            objectIndex = slotIndex+208;
            break;
        }
    }
    if (objectIndex == -1) return -1;
    pool->slots[slotIndex].alternateRepresentation = source->alternateRepresentation;
    if (source->alternateRepresentation == 0) {
        Object3D* object = &pool->slots[slotIndex].content.object;
        object->Initialize();
        pool->slots[slotIndex].templateKey = source->key;
        source->object.ShallowCloneTo(object);
        object->position_ = params->position;
        object->rotation_ = params->rotation;
        object->SetScale(params->scale.x,params->scale.y,params->scale.z);
        if (params->animation[0] == 0)
            object->SetBCFGAnimationByIndex(0,params->animationFlags);
        else
            object->SetAnimationByName(params->animation,params->animationFlags);
        pool->slots[slotIndex].valueB0 = params->value12;
        pool->slots[slotIndex].valueB2 = params->value14;
        pool->slots[slotIndex].valueB4 = params->value16;
        pool->slots[slotIndex].valueB6 = params->value18;
        pool->slots[slotIndex].valueB8 = params->value1A;
        pool->slots[slotIndex].valueBC = params->value1C;
        pool->slots[slotIndex].vectorC0 = params->vector20;
        pool->slots[slotIndex].sourceFlag0 = params->flag0 != 0;
        pool->slots[slotIndex].sourceFlag2 = params->flag2 != 0;
        pool->slots[slotIndex].sourceFlag1 = params->flag1 != 0;
        pool->slots[slotIndex].sourceFlag6 = params->flag6 != 0;
        pool->slots[slotIndex].sourceFlag7 = params->flag7 != 0;
        GameState_SetIndexedObjectAndSlot(state,objectIndex,(GameObject*)object);
        if (object->pModel_) {
            ModelRenderContext* context = GetModel3DContext(object->pModel_);
            NSBXXNameList* bones = context->internalModel_ ? &context->internalModel_->boneList_ : 0;
            int bone = bones ? NNS_G3dGetResDictIdxByName(bones,ObjectPool_SpawnFromTemplate_TextZure) : -1;
            if (bone >= 0)
                SetModelRenderContextRenderCommandHook(context,Graphics_SubmitScaledBillboardMatrix,0,7,1);
        }
    } else {
        pool->slots[slotIndex].templateKey = source->key;
        pool->slots[slotIndex].valueB0 = params->value12;
        pool->slots[slotIndex].valueB2 = params->value14;
        pool->slots[slotIndex].valueB4 = params->value16;
        pool->slots[slotIndex].valueB6 = params->value18;
        pool->slots[slotIndex].valueB8 = params->value1A;
        pool->slots[slotIndex].valueBC = params->value1C;
        pool->slots[slotIndex].vectorC0 = params->vector20;
        pool->slots[slotIndex].sourceFlag0 = params->flag0 != 0;
        pool->slots[slotIndex].sourceFlag2 = params->flag2 != 0;
        pool->slots[slotIndex].sourceFlag1 = params->flag1 != 0;
        pool->slots[slotIndex].sourceFlag6 = params->flag6 != 0;
        pool->slots[slotIndex].sourceFlag7 = params->flag7 != 0;
        GameState_SetIndexedObjectAndSlot(state,objectIndex,(GameObject*)&source->object);
        ResourceTracks_ClearBindingOwner(&pool->slots[slotIndex].content.binding);
        ResourceTracks_BindResourcesAndInitializePlayback(&pool->slots[slotIndex].content.binding,
            source->resourceDescriptor,&source->object,source->resourceC);
        Matrix4x3 translation;
        MTX_Identity43_(&translation);
        Mat4x3_ApplyTranslation(&translation,&translation,params->position.x,params->position.y,params->position.z);
        ResourceInstance* instance = pool->slots[slotIndex].content.binding.instance;
        instance->transform = translation;
        Vector3fix scale = ObjectPoolSpawnFromTemplate_UnknownRoleInitializedBytes;
        source->object.SetScale(&scale);
        if (params->flag3 && pool->slots[slotIndex].content.binding.instance)
            pool->slots[slotIndex].content.binding.instance->enabled = 0;
        if (params->flag4 && pool->slots[slotIndex].content.binding.instance)
            pool->slots[slotIndex].content.binding.instance->parameter = params->value18;
        if (params->flag5 && pool->slots[slotIndex].content.binding.instance)
            pool->slots[slotIndex].content.binding.instance->option39 = 1;
        if (params->flag6 && pool->slots[slotIndex].content.binding.instance)
            pool->slots[slotIndex].content.binding.instance->option3A = 1;
        if (params->flag7 && pool->slots[slotIndex].content.binding.instance)
            pool->slots[slotIndex].content.binding.instance->option3B = 1;
    }
    return objectIndex;
}
