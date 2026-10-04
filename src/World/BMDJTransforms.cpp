#include "World/BMDJ.h"

extern const Vector3i data_020e6dfc = { 0x1000, 0x1000, 0x1000 };

void InitializeBMDJTransforms(Zone3D_BMDJStruct::InstanceEntry* instance)
{
    Vector3i position = { 0, 0, 0 };
    Vector3i scale = data_020e6dfc;
    int angle = 0;
    ApplyBMDJTransforms(instance, &position, &angle, &scale);
}

void ApplyBMDJTransforms(Zone3D_BMDJStruct::InstanceEntry* instance, const Vector3i* parentPosition, const int* parentAngle, const Vector3i* parentScale)
{
    Matrix3x3 rotation;
    fix32_t cosine = fix32cos(*parentAngle);
    fix32_t sine = fix32sin(*parentAngle);
    Mat3x3_WriteRotationY(&rotation, sine, cosine);
    if (instance->definition)
    {
        Vector3i position;
        Mat3x3_ApplyToVector((Vector3i*)instance->definition->unk_8, &rotation, &position);
        Vector3fix_Add(&position, parentPosition, &instance->position);
        instance->worldAngle = fix32ReduceAngle0To2Pi(*parentAngle + (short)instance->definition->unk_16);
        instance->scale.x = (int)(((long long)(short)instance->definition->unk_1a * parentScale->x + 0x800) >> 12);
        instance->scale.y = (int)(((long long)(short)instance->definition->unk_1c * parentScale->y + 0x800) >> 12);
        instance->scale.z = (int)(((long long)(short)instance->definition->unk_1e * parentScale->z + 0x800) >> 12);
    }
    Zone3D_BMDJStruct::InstanceEntry* sibling = instance->nextSibling;
    if (sibling)
    {
        for (; sibling; sibling = sibling->nextSibling)
        {
            if (sibling->definition)
            {
                Vector3i position;
                Mat3x3_ApplyToVector((Vector3i*)sibling->definition->unk_8, &rotation, &position);
                Vector3fix_Add(&position, parentPosition, &sibling->position);
                sibling->worldAngle = fix32ReduceAngle0To2Pi(*parentAngle + (short)sibling->definition->unk_16);
                sibling->scale.x = (int)(((long long)(short)sibling->definition->unk_1a * parentScale->x + 0x800) >> 12);
                sibling->scale.y = (int)(((long long)(short)sibling->definition->unk_1c * parentScale->y + 0x800) >> 12);
                sibling->scale.z = (int)(((long long)(short)sibling->definition->unk_1e * parentScale->z + 0x800) >> 12);
            }
            if (sibling->firstChild)
            {
                int angle = sibling->worldAngle;
                ApplyBMDJTransforms(sibling->firstChild, &sibling->position, &angle, &sibling->scale);
            }
        }
    }
    if (instance->firstChild)
    {
        int angle = instance->worldAngle;
        ApplyBMDJTransforms(instance->firstChild, &instance->position, &angle, &instance->scale);
    }
}
