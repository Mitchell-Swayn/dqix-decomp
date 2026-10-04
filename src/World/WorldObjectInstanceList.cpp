#include "World/WorldObjectInstanceList.h"

void WorldObjectInstanceList::SetObject(Object3D* object)
{

    this->object = object;
    if (!this->object) return;
    this->object->SetScale(266, 266, 266);
    this->object->MaybeSetBCFGAnimation(0, 0);
}

void WorldObjectInstanceList::ClearInstances()
{
    head = 0;
}

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


