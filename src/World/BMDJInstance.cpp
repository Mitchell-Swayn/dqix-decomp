#include "World/BMDJ.h"

void ResetBMDJInstance(Zone3D_BMDJStruct::InstanceEntry* instance)
{
    instance->id = 0xffff;
    instance->flags = 0;
    instance->countdown = 31;
    instance->unknown_4_high = 0;
    instance->definition = 0;
    instance->resource = NULL;
    instance->position.x = 0;
    instance->position.y = 0;
    instance->position.z = 0;
    instance->worldAngle = 0;
    instance->scale.x = 0x1000;
    instance->scale.y = 0x1000;
    instance->scale.z = 0x1000;
    instance->parent = 0;
    instance->firstChild = 0;
    instance->nextSibling = 0;
    instance->object = NULL;
    instance->targetAngle = 0;
    instance->rotationSpeed = 0;
    instance->currentAngle = 0;
    instance->unknown_58 = 0;
    instance->unknown_5c = 0;
    instance->unknown_60 = 0;
    instance->unknown_64 = 0;
    instance->unknown_68 = 0;
    instance->unknown_6c = 0;
}
