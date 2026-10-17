#include "World/WorldScriptRecordNode.h"
#include "Memory/SafeAllocator.h"

extern "C" void CopyLinkedRecordFields(WorldScriptRecordNode*,
                               const WorldScriptRecordNode*);

// Original: arm9/main @ 0x0208DF94; symbol: func_0208df94; size: 0x6C.
extern "C" void WorldScriptRecordList_AllocateAndAppendNode(WorldScriptRecordList* list,
                               SafeAllocator* allocator,
                               const WorldScriptRecordNode* source)
{
    WorldScriptRecordNode* node =
        (WorldScriptRecordNode*)allocator->Allocate(sizeof(WorldScriptRecordNode));
    WorldScriptRecordNode* tail = list->head;
    if (tail != 0)
    {
        while (tail->next != 0) tail = tail->next;
        CopyLinkedRecordFields(node, source);
        tail->next = node;
    }
    else
    {
        list->head = node;
        CopyLinkedRecordFields(node, source);
    }
    list->count = (short)(list->count + 1);
}
