#include "World/Zone3D.h"

struct ZoneType2StoredState
{
    int unknown_0;
    unsigned short featureMask;
};
extern "C" void* func_02027ca4();
extern "C" ZoneType2StoredState* func_02028bd0(void*, unsigned short);

// These reset the feature's active bit and its linked instance flags. Names
// describe observed movement behavior; the exact gameplay role remains unknown.
void Zone3D::ReverseType2FeatureMotion(ZoneFeatures::Opcode6aEntry* feature)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindType2BMDJInstance(feature);
    if (!instance) return;
    instance->flags &= ~1;
    instance->flags &= ~4;
    for (int i = 0; i < unknown_82c_; ++i)
    {
        Zone3D_BMDJStruct::InstanceEntry* child = collisionInstances_[i];
        if (child->parent == instance)
        {
            child->flags &= ~1;
            break;
        }
    }
    if (feature->unk_2c.type2.unk_2_high & 0x20)
    {
        Vector3fix target, displacement;
        Vector3fixMultiplyScalar(&instance->movementDirection, feature->unk_2c.type2.unk_40, &displacement);
        Vector3fix_Add(&instance->position, &displacement, &target);
        instance->movementDirection.x = -instance->movementDirection.x;
        instance->movementDirection.y = -instance->movementDirection.y;
        instance->movementDirection.z = -instance->movementDirection.z;
        instance->targetPosition = target;
        instance->movementStep = 0x266;
    }
    else
    {
        if (feature->unk_2c.type2.unk_2_high & 2)
            instance->targetAngle = 128.68f + instance->worldAngle;
        else
            instance->targetAngle = instance->worldAngle - 128.68f;
        instance->rotationSpeed = 0x199;
        instance->countdown = 31;
        instance->flags |= 0x80;
    }
    feature->unk_2c.type2.unk_2_high &= ~1;
    unk_830[0] = 15;
    if (!(feature->unk_2c.type2.unk_2_high & 8))
    {
        int index = GetType2FeatureIndex(feature);
        ZoneType2StoredState* stored = func_02028bd0(func_02027ca4(), currentZoneID_);
        if (stored) stored->featureMask &= ~(1 << index);
    }
}

void Zone3D::ResetType2FeaturePosition(ZoneFeatures::Opcode6aEntry* feature)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindType2BMDJInstance(feature);
    if (!instance) return;
    instance->flags &= ~1;
    instance->flags &= ~4;
    for (int i = 0; i < unknown_82c_; ++i)
    {
        Zone3D_BMDJStruct::InstanceEntry* child = collisionInstances_[i];
        if (child->parent == instance)
        {
            child->flags &= ~1;
            break;
        }
    }
    if (feature->unk_2c.type2.unk_2_high & 0x20)
    {
        short angle = fix32ReduceAngle0To2Pi((short)(feature->unk_20 + 0x1922));
        fix32_t cosine = fix32cos(angle);
        Vector3fix displacement;
        displacement.x = fix32sin(angle);
        displacement.y = 0;
        displacement.z = cosine;
        Vector3fix_Normalize(&displacement, &displacement);
        Vector3fixMultiplyScalar(&displacement, -feature->unk_2c.type2.unk_40, &displacement);
        Vector3fix direction;
        Vector3fix_Normalize(&displacement, &direction);
        instance->movementDirection = direction;
        Vector3fix position;
        Vector3fix_Add(&instance->position, &displacement, &position);
        instance->position = position;
    }
    feature->unk_2c.type2.unk_2_high &= ~1;
    unk_830[0] = 15;
    if (!(feature->unk_2c.type2.unk_2_high & 8))
    {
        int index = GetType2FeatureIndex(feature);
        ZoneType2StoredState* stored = func_02028bd0(func_02027ca4(), currentZoneID_);
        if (stored) stored->featureMask &= ~(1 << index);
    }
}
