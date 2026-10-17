#include "World/Zone3D.h"
#include "GameState/GameState.h"

// Unlike FindBMDJInstance, this continues past a matching group and can return
// an instance from a later group with the same ID.
// Original: arm9/main @ 0x02019508; symbol: _ZN6Zone3D20FindLastBMDJInstanceEii; size: 0x60.
Zone3D_BMDJStruct::InstanceEntry* Zone3D::FindLastBMDJInstance(int groupID, int instanceID)
{
    Zone3D_BMDJStruct::InstanceEntry* result = NULL;
    for (Zone3D_BMDJStruct* group = firstBMDJStruct_41c_; group; group = group->pNext_)
    {
        if (group->unknown_0_ == groupID)
        {
            int count = group->scriptData_.counter_10;
            Zone3D_BMDJStruct::InstanceEntry* instance = group->ptr_44;
            for (int i = 0; i < count; ++i, ++instance)
            {
                if (instance->id == instanceID)
                {
                    result = instance;
                    break;
                }
            }
        }
    }
    return result;
}

// Bit 0x20 stores the inverse of flag 4 while these definition-based overrides
// are active. The alternate mode's gameplay interpretation is still unknown.
// Original: arm9/main @ 0x02019568; symbol: _ZN6Zone3D23ApplyBMDJFlag4OverridesEb; size: 0x110.
void Zone3D::ApplyBMDJFlag4Overrides(bool alternate)
{
    GameState::GetInstance();
    int timeOfDay = LightingManager::GetInstance()->timeOfDayIndex_;
    for (Zone3D_BMDJStruct* group = firstBMDJStruct_41c_; group; group = group->pNext_)
    {
        int groupID = 0;
        if (group->unknown_0_ >= 0) groupID = (unsigned char)group->unknown_0_;
        for (int i = 0; i < group->scriptData_.counter_10; ++i)
        {
            Zone3D_BMDJStruct::StructSize20* definition = group->scriptData_.GetStruct20(i);
            Zone3D_BMDJStruct::InstanceEntry* instance = &group->ptr_44[i];
            if (instance->flags & 4) instance->flags &= ~0x20;
            else instance->flags |= 0x20;
            if (definition->flags_6 & 0x10) UpdateBMDJFlag4(instance, groupID, 1);
            if (!(definition->flags_6 & (1 << timeOfDay))) UpdateBMDJFlag4(instance, groupID, 0);
            if (alternate)
            {
                if (definition->flags_6 & 0x20) UpdateBMDJFlag4(instance, groupID, 0);
            }
            else
            {
                if (definition->flags_6 & 0x40) UpdateBMDJFlag4(instance, groupID, 0);
            }
            instance->flags &= ~0x40;
        }
    }
}

// Original: arm9/main @ 0x02019678; symbol: _ZN6Zone3D25RestoreBMDJFlag4OverridesEv; size: 0x84.
void Zone3D::RestoreBMDJFlag4Overrides()
{
    GameState::GetInstance();
    LightingManager::GetInstance();
    for (Zone3D_BMDJStruct* group = firstBMDJStruct_41c_; group; group = group->pNext_)
    {
        for (int i = 0; i < group->scriptData_.counter_10; ++i)
        {
            group->scriptData_.GetStruct20(i);
            Zone3D_BMDJStruct::InstanceEntry* instance = &group->ptr_44[i];
            if (!(instance->flags & 0x40))
            {
                int groupID = 0;
                if (group->unknown_0_ >= 0) groupID = (unsigned char)group->unknown_0_;
                UpdateBMDJFlag4(instance, groupID, instance->flags & 0x20);
            }
        }
    }
}

// Original: arm9/main @ 0x020196FC; symbol: _ZN6Zone3D19GetBMDJGroupAtIndexEi; size: 0x2C.
Zone3D_BMDJStruct* Zone3D::GetBMDJGroupAtIndex(int index)
{
    Zone3D_BMDJStruct* group = firstBMDJStruct_41c_;
    for (int i = 0; i < index; ++i)
    {
        if (!group) return NULL;
        group = group->pNext_;
    }
    return group;
}
