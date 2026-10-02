#include "World/Zone3D.h"
#include "World/BMDJStateNotification.h"
#include "GameState/GameState.h"

extern "C" void* func_0205ec34();
extern "C" void func_02064b24(void*, int, int, BMDJStateNotification*);
extern "C" void func_0205eaa0(void*, int, int);
extern "C" void func_020397cc(GameObject*, bool);
extern "C" void func_ov017_021d196c(unsigned short, unsigned short, bool);
extern "C" void* func_02027ca4();
extern "C" void* func_02028bd0(void*, unsigned short);
extern "C" void func_02028c64(void*, int);
extern char data_02108760[];

struct Type2FeatureSoundTable
{
    int ids[5];
};
extern const Type2FeatureSoundTable gType2FeatureSounds = { { 200, 201, 202, 203, 204 } };

void Zone3D::ActivateType2Feature(ZoneFeatures::Opcode6aEntry* feature, bool playSound, bool force, int notify)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindType2BMDJInstance(feature);
    if (!instance) return;
    if (!force && (feature->unk_2c.type2.unk_2_high & 8)) return;
    if (!force && (feature->unk_2c.type2.unk_2_high & 4)) return;
    if (!force)
    {
        void* state = func_0205ec34();
        BMDJStateNotification notification;
        notification.angle = feature->unk_20;
        notification.instanceID = feature->unk_2c.type2.unk_1;
        notification.groupID = feature->unk_2c.type2.unk_0;
        notification.zoneID = currentZoneID_;
        func_02064b24(state, 0x11, 0x6c, &notification);
        func_02064b24(state, 3, 0x6c, &notification);
        if (feature->unk_2c.type2.unk_2_high & 4)
        {
            feature->unk_2c.type2.unk_2_high &= ~4;
            feature->unk_2c.type2.unk_2_high &= ~1;
            return;
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
        Vector3fixMultiplyScalar(&displacement, feature->unk_2c.type2.unk_40, &displacement);
        Vector3fix direction;
        Vector3fix_Normalize(&displacement, &direction);
        instance->movementDirection = direction;
        Vector3fix target;
        Vector3fix_Add(&instance->position, &displacement, &target);
        instance->targetPosition = target;
        instance->movementStep = 0x266;
    }
    else
    {
        int angle = (feature->unk_2c.type2.unk_2_high & 0x40) ? 0x1922 : 0x141b;
        if (feature->unk_2c.type2.unk_2_high & 0x100)
        {
            if (feature->unk_2c.type2.unk_2_high & 0x80)
            {
                instance->flags |= 0x10;
                if (feature->unk_2c.type2.unk_2_high & 2)
                    instance->currentAngle = instance->targetAngle = instance->worldAngle - angle;
                else
                    instance->currentAngle = instance->targetAngle = instance->worldAngle + angle;
            }
            else instance->flags |= 4;
        }
        else
        {
            if (feature->unk_2c.type2.unk_2_high & 0x80) instance->flags |= 0x10;
            if (feature->unk_2c.type2.unk_2_high & 2) instance->targetAngle = instance->worldAngle - angle;
            else instance->targetAngle = instance->worldAngle + angle;
        }
        instance->rotationSpeed = 0x199;
    }
    feature->unk_2c.type2.unk_2_high |= 1;
    instance->flags |= 1;
    for (int i = 0; i < unknown_82c_; ++i)
    {
        Zone3D_BMDJStruct::InstanceEntry* child = collisionInstances_[i];
        if (child->parent == instance)
        {
            child->flags |= 1;
            break;
        }
    }
    ZoneFeatures::Opcode6aEntry* other = bFeatures_.GetTypeEntries(2);
    for (; other; other = other->pNext)
    {
        if (other->unk_2c.type2.unk_0 == feature->unk_2c.type2.unk_0 &&
            other->unk_2c.type2.unk_1 == feature->unk_2c.type2.unk_1)
            other->unk_2c.type2.unk_2_high |= 1;
    }
    if (playSound)
    {
        Type2FeatureSoundTable sounds = gType2FeatureSounds;
        func_0205eaa0(data_02108760, sounds.ids[feature->unk_2c.type2.unk_2_low], 0);
    }
    if (force && (feature->unk_2c.type2.unk_2_high & 8))
    {
        GameObject* protagonist = GameState::GetInstance()->GetProtagonist();
        // The short at GameObject+0xb2 has no established semantic name.
        *(short*)&protagonist->unk_ac[6] = 0;
        func_020397cc(protagonist, true);
        unk_830[0] = 8;
        return;
    }
    int index = GetType2FeatureIndex(feature);
    if (force && notify) func_ov017_021d196c(currentZoneID_, index, playSound);
    void* stored = func_02028bd0(func_02027ca4(), currentZoneID_);
    if (stored && !(feature->unk_2c.type2.unk_2_high & 0x200)) func_02028c64(stored, index);
}
