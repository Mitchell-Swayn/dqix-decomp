#include "World/WorldObjectInstanceList.h"

// Original: arm9/main @ 0x0208F36C; symbol: _ZN23WorldObjectInstanceList9SetObjectEP8Object3D; size: 0x3C.
void WorldObjectInstanceList::SetObject(Object3D* object)
{

    this->object = object;
    if (!this->object) return;
    this->object->SetScale(266, 266, 266);
    this->object->SetBCFGAnimationByIndex(0, 0);
}

// Original: arm9/main @ 0x0208F3A8; symbol: _ZN23WorldObjectInstanceList14ClearInstancesEv; size: 0xC.
void WorldObjectInstanceList::ClearInstances()
{
    head = 0;
}

// Original: arm9/main @ 0x0208F3B4; symbol: _ZN23WorldObjectInstanceList14RemoveInstanceEi; size: 0x5C.
void WorldObjectInstanceList::RemoveInstance(int key)
{
    Instance* current;
    Instance* previous;
    Instance* first = head;
    previous = 0;
    current = first;
    while (current)
    {
        if (current->key == key)
        {
            if (current == first)
            {
                head = current->next;
                return;
            }
            if (!current->next)
            {
                previous->next = 0;
                return;
            }
            previous->next = current->next;
            return;
        }
        previous = current;
        current = current->next;
    }
}


