#include "World/Zone3D.h"
#include "GameState/GameState.h"

struct ZoneLightingOverride
{
    char unknown_0[5];
    unsigned char timeOfDay;
};
extern "C" bool FieldBattle_IsSceneActive(void*);
extern "C" ZoneLightingOverride* FieldBattle_GetEncounterRequest(void*);

// Original: arm9/main @ 0x020177D4; symbol: _ZN6Zone3D18BuildBMDJInstancesEP17Zone3D_BMDJStructP13SafeAllocator; size: 0x2C0.
void Zone3D::BuildBMDJInstances(Zone3D_BMDJStruct* group, SafeAllocator* allocator)
{
    GameState::GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    int count = group->scriptData_.counter_10;
    group->ptr_44 = (Zone3D_BMDJStruct::InstanceEntry*)allocator->Allocate(count * sizeof(Zone3D_BMDJStruct::InstanceEntry));
    if (!group->ptr_44) return;
    for (int i = 0; i < count; ++i)
    {
        Zone3D_BMDJStruct::StructSize20* definition = group->scriptData_.GetStruct20(i);
        Zone3D_BMDJStruct::InstanceEntry* instance = &group->ptr_44[i];
        ResetBMDJInstance(instance);
        instance->id = definition->maybeID;
    }
    for (int i = 0; i < count; ++i)
    {
        Zone3D_BMDJStruct::StructSize20* definition = group->scriptData_.GetStruct20(i);
        int j;
        Zone3D_BMDJStruct::InstanceEntry* instances = group->ptr_44;
        int parentID = definition->unk_4;
        Zone3D_BMDJStruct::InstanceEntry* instance = &instances[i];
        if (parentID > -1)
        {
            for (j = 0; j < count; ++j)
            {
                Zone3D_BMDJStruct::InstanceEntry* parent = &instances[j];
                if (parentID == parent->id)
                {
                    instance->parent = parent;
                    AppendBMDJChild(parent, instance);
                    break;
                }
            }
        }
        else if (i != 0)
            AppendBMDJSibling(instances, instance);
    }
    int timeOfDay = lighting->timeOfDayIndex_;
    void* overrideContext = GameResources_GetInstance()->unknown_ptr_3718;
    if (overrideContext && FieldBattle_IsSceneActive(overrideContext))
        timeOfDay = FieldBattle_GetEncounterRequest(overrideContext)->timeOfDay;
    for (int i = 0; i < count; ++i)
    {
        Zone3D_BMDJStruct::StructSize20* definition = group->scriptData_.GetStruct20(i);
        Zone3D_BMDJStruct::InstanceEntry* instance = &group->ptr_44[i];
        instance->definition = definition;
        instance->movementStep = 0;
        Vector3i position = *(Vector3i*)definition->unk_8;
        if (!instance->parent)
            Vector3fix_Add(&position, &group->vec_48_, &position);
        if (definition->flags_6 & 0x10)
            instance->flags |= 4;
        else if (definition->flags_6 & (1 << timeOfDay))
            instance->flags &= ~4;
        else
            instance->flags |= 4;
        if (definition->unk_2 < 0)
            instance->resource = &group->ptr_40[definition->maybeID];
        else
        {
            int index = group->scriptData_.FindStructCByID(definition->unk_2);
            if (index >= 0) instance->resource = &group->ptr_40[index];
        }
        Zone3D_BMDJStruct::ObjectEntry* resource = instance->resource;
        if (!resource) continue;
        if (resource->kind == 0 && !resource->model) instance->resource = NULL;
        if (resource->kind == 1 && !resource->unknown_4) instance->resource = NULL;
        if (resource->kind == 2 && !resource->object) instance->resource = NULL;
        if (resource->kind == 2 && instance->resource)
        {
            instance->object = (Object3D*)allocator->Allocate(sizeof(Object3D));
            if (!instance->object)
            {
                instance->resource = NULL;
                continue;
            }
            instance->object->Initialize();
            resource->object->ShallowCloneTo(instance->object);
        }
    }
    InitializeBMDJTransforms(group->ptr_44);
}
