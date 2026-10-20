#include "World/BMDJ.h"

// Original: arm9/main @ 0x020130B0; symbol: _Z15AppendBMDJChildPN17Zone3D_BMDJStruct13InstanceEntryES1_; size: 0x30.
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

// Original: arm9/main @ 0x020130E0; symbol: _Z17AppendBMDJSiblingPN17Zone3D_BMDJStruct13InstanceEntryES1_; size: 0x2C.
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
