#include "World/BMDJ.h"

void AppendBMDJChild(Zone3D_BMDJStruct::InstanceEntry* parent, Zone3D_BMDJStruct::InstanceEntry* child)
{
    child->parent = parent;
    Zone3D_BMDJStruct::InstanceEntry* last = parent->firstChild;
    if (!last)
    {
        parent->firstChild = child;
        return;
    }
    while (last->nextSibling) last = last->nextSibling;
    last->nextSibling = child;
}

void AppendBMDJSibling(Zone3D_BMDJStruct::InstanceEntry* first, Zone3D_BMDJStruct::InstanceEntry* next)
{
    Zone3D_BMDJStruct::InstanceEntry* last = first->nextSibling;
    if (!last)
    {
        first->nextSibling = next;
        return;
    }
    while (last->nextSibling) last = last->nextSibling;
    last->nextSibling = next;
}
