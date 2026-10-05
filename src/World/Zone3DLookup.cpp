#include "World/Zone3D.h"

Zone3D_BMDJStruct::InstanceEntry* Zone3D::FindBMDJInstance(int groupID, unsigned short instanceID)
{
    if (unknown_424_) return NULL;
    Zone3D_BMDJStruct* group = firstBMDJStruct_41c_;
    for (; group; group = group->pNext_)
        if (group->unknown_0_ == groupID) break;
    Zone3D_BMDJStruct::InstanceEntry* result = NULL;
    if (!group) return result;
    int count = group->scriptData_.counter_10;
    for (int i = 0; i < count; ++i)
        if (instanceID == group->ptr_44[i].id)
        {
            result = &group->ptr_44[i];
            break;
        }
    return result;
}

// Types 10 and 11 share a position and distance limit. Their gameplay roles
// remain unresolved. Prefer the nearest entry within its own distance limit;
// otherwise return the nearest entry considered outside that limit.
ZoneFeatures::Opcode6aEntry* Zone3D::FindNearestType10Feature(const Vector3fix* point)
{
    ZoneFeatures::Opcode6aEntry* nearest = NULL;
    ZoneFeatures::Opcode6aEntry* entry = bFeatures_.GetTypeEntries(10);
    Vector3fix position;
    position.x = point->x * 6;
    position.y = point->y * 6;
    position.z = point->z * 6;
    fix32_t nearestDistance = 0xffff000;
    fix32_t outsideDistance = nearestDistance;
    position.x -= mapListInfo_.unknown_38;
    position.z -= mapListInfo_.unknown_3c;
    ZoneFeatures::Opcode6aEntry* outside = NULL;
    for (; entry; entry = entry->pNext)
    {
        fix32_t distance = Vector3fix_Distance(&entry->unk_8.vec, &position);
        if (distance < nearestDistance)
        {
            if (distance <= entry->unk_2c.type10.unk_10)
            {
                nearestDistance = distance;
                nearest = entry;
            }
            else if (distance < outsideDistance)
            {
                outsideDistance = distance;
                outside = entry;
            }
        }
    }
    if (nearest) return nearest;
    if (outside) return outside;
    return NULL;
}

ZoneFeatures::Opcode6aEntry* Zone3D::FindType10Feature(unsigned short id)
{
    ZoneFeatures::Opcode6aEntry* entry = bFeatures_.GetTypeEntries(10);
    for (; entry; entry = entry->pNext)
        if (entry->unk_2c.type10.unk_0 == id) return entry;
    return NULL;
}

ZoneFeatures::Opcode6aEntry* Zone3D::FindNearestType11Feature(const Vector3fix* point)
{
    ZoneFeatures::Opcode6aEntry* nearest = NULL;
    ZoneFeatures::Opcode6aEntry* entry = bFeatures_.GetTypeEntries(11);
    Vector3fix position;
    position.x = point->x * 6;
    position.y = point->y * 6;
    position.z = point->z * 6;
    fix32_t nearestDistance = 0xffff000;
    fix32_t outsideDistance = nearestDistance;
    position.x -= mapListInfo_.unknown_38;
    position.z -= mapListInfo_.unknown_3c;
    ZoneFeatures::Opcode6aEntry* outside = NULL;
    for (; entry; entry = entry->pNext)
    {
        fix32_t distance = Vector3fix_Distance(&entry->unk_8.vec, &position);
        if (distance < nearestDistance)
        {
            if (distance <= entry->unk_2c.type10.unk_10)
            {
                nearestDistance = distance;
                nearest = entry;
            }
            else if (distance < outsideDistance)
            {
                outsideDistance = distance;
                outside = entry;
            }
        }
    }
    if (nearest) return nearest;
    if (outside) return outside;
    return NULL;
}
