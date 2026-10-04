#include "World/WorldScriptRecordNode.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_0208e000(WorldScriptRecordNode*,
                               const WorldScriptRecordNode*);

extern "C" void func_0208df94(WorldScriptRecordList* list,
                               SafeAllocator* allocator,
                               const WorldScriptRecordNode* source)
{
    WorldScriptRecordNode* node =
        (WorldScriptRecordNode*)allocator->Allocate(sizeof(WorldScriptRecordNode));
    WorldScriptRecordNode* tail = list->head;
    if (tail != 0)
    {
        while (tail->next != 0) tail = tail->next;
        func_0208e000(node, source);
        tail->next = node;
    }
    else
    {
        list->head = node;
        func_0208e000(node, source);
    }
    list->count = (short)(list->count + 1);
}
