#pragma once
#include "World/Object3D.h"

// Reuses one Object3D to draw a linked list of placements. The flag and
// floating-point field retain neutral names until their consumers are recovered.
class WorldObjectInstanceList
{
public:
    struct Instance
    {
        int key;
        Vector3i position;
        int animationTime;
        Instance* next;
    };
    unsigned char unknown0;
    float unknown4;
    Object3D* object;
    Instance* head;

    WorldObjectInstanceList();
    ~WorldObjectInstanceList();
    void UpdatePersistentPlacementFlags();
    void Reset();
    void SetObject(Object3D* object);
    void ClearInstances();
    void RemoveInstance(int key);
    void Draw();
};

