#include "World/Zone3D.h"

void Zone3D::ApplyType2InstanceFlags()
{
    ZoneFeatures::Opcode6aEntry* feature = bFeatures_.GetTypeEntries(2);
    for (; feature; feature = feature->pNext)
    {
        Zone3D_BMDJStruct::InstanceEntry* instance = FindType2BMDJInstance(feature);
        bool flag = (feature->unk_2c.type2.unk_2_high & 0x80) != 0;
        if (instance)
        {
            instance->flags |= 8;
            if (flag) instance->flags |= 0x10;
        }
    }
}

Zone3D_BMDJStruct::InstanceEntry* Zone3D::FindType2BMDJInstance(ZoneFeatures::Opcode6aEntry* feature)
{
    if (feature->maybeType != 2) return NULL;
    if (unknown_424_) return NULL;
    Zone3D_BMDJStruct* group = firstBMDJStruct_41c_;
    for (; group; group = group->pNext_)
        if (group->unknown_0_ == feature->unk_2c.type2.unk_0) break;
    Zone3D_BMDJStruct::InstanceEntry* result = NULL;
    if (!group) return result;
    int count = group->scriptData_.counter_10;
    for (int i = 0; i < count; ++i)
    {
        if (feature->unk_2c.type2.unk_1 == group->ptr_44[i].id)
        {
            result = &group->ptr_44[i];
            break;
        }
    }
    return result;
}

int Zone3D::GetType2FeatureIndex(ZoneFeatures::Opcode6aEntry* feature)
{
    ZoneFeatures::Opcode6aEntry* entry = bFeatures_.GetOpcode6aEntry(0);
    int count;
    int index = 0;
    count = bFeatures_.arraySize6a_;
    for (int i = 0; i < count; ++entry, ++i)
    {
        if (entry->maybeType == 2)
        {
            if (entry == feature) return index;
            ++index;
        }
    }
    return -1;
}

ZoneFeatures::Opcode6aEntry* Zone3D::GetType2Feature(int index)
{
    ZoneFeatures::Opcode6aEntry* entry = bFeatures_.GetOpcode6aEntry(0);
    int count = bFeatures_.arraySize6a_;
    for (int i = 0; i < count; ++entry, ++i)
    {
        if (entry->maybeType == 2)
        {
            if (!index) return entry;
            --index;
        }
    }
    return NULL;
}
