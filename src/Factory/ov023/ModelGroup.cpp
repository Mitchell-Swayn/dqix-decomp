#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"

struct ZoneState2754;

// Partial layout of the 0xc20-byte model group allocated by overlay 23.
// The ten Object3D instances are real contiguous subobjects, not raw offsets.
struct Ov23ModelGroup
{
    Object3D objects[10];
    SafeAllocator allocators[10];
    SafeAllocator auxiliaryAllocator;
    unsigned char unknown_794[0x460];
    short taskIDs[12];
    ZoneState2754* zoneState;
    unsigned char unknown_c10;
    unsigned char flag_c11;
    unsigned char unknown_c12[0xe];
};

typedef char ObjectSizeCheck[sizeof(Object3D) == 0xac ? 1 : -1];
typedef char GroupSizeCheck[sizeof(Ov23ModelGroup) == 0xc20 ? 1 : -1];
typedef char TaskOffsetCheck[offsetof(Ov23ModelGroup, taskIDs) == 0xbf4 ? 1 : -1];
typedef char StateOffsetCheck[offsetof(Ov23ModelGroup, zoneState) == 0xc0c ? 1 : -1];
typedef char FlagOffsetCheck[offsetof(Ov23ModelGroup, flag_c11) == 0xc11 ? 1 : -1];
typedef char RotationOffsetCheck[offsetof(Object3D, rotation_) == 0x50 ? 1 : -1];

#pragma dont_inline on
extern "C" void func_ov023_021e60c4(Object3D* object, const Vector3fix* rotation);

extern "C" void func_ov023_021e6088(Ov23ModelGroup* group, const Vector3fix* rotation)
{
    func_ov023_021e60c4(&group->objects[0], rotation);
    func_ov023_021e60c4(&group->objects[6], rotation);
    func_ov023_021e60c4(&group->objects[1], rotation);
    func_ov023_021e60c4(&group->objects[5], rotation);
}

extern "C" void func_ov023_021e60c4(Object3D* object, const Vector3fix* rotation)
{
    object->rotation_.x = rotation->x;
    object->rotation_.y = rotation->y;
    object->rotation_.z = rotation->z;
}

extern "C" void func_ov023_021e60e0(Ov23ModelGroup* group, fix32_t yRotation)
{
    Vector3fix rotation = {0, 0, 0};
    rotation.y = yRotation;
    func_ov023_021e60c4(&group->objects[0], &rotation);
    func_ov023_021e60c4(&group->objects[6], &rotation);
    func_ov023_021e60c4(&group->objects[1], &rotation);
    func_ov023_021e60c4(&group->objects[5], &rotation);
}

extern "C" Vector3fix func_ov023_021e613c(const Object3D* object)
{
    return object->rotation_;
}

extern "C" void func_ov023_021e6150(Ov23ModelGroup* group, unsigned char flag)
{
    group->flag_c11 = flag;
}

extern "C" void func_ov023_021e6158(Ov23ModelGroup* group, int index)
{
    group->objects[index].unknown_2_ = -1;
}

extern "C" void func_ov023_021e616c(Ov23ModelGroup* group)
{
    for (int i = 0; i < 10; ++i)
        group->objects[i].unknown_2_ = -1;
}

// Existing empty lifecycle hook, retained with its original call sites.
extern "C" void func_ov023_021e6194(Ov23ModelGroup*)
{
}

extern "C" void func_ov023_021e6198(Ov23ModelGroup* group, ZoneState2754* zoneState)
{
    group->zoneState = zoneState;
}

extern "C" void func_ov023_021e61a0(Ov23ModelGroup* group)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    for (int i = 0; i < 12; ++i) {
        if (group->taskIDs[i] > -1)
            loader->RemoveTask(group->taskIDs[i]);
        group->taskIDs[i] = -1;
    }
}
