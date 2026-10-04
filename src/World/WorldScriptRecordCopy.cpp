#include "World/WorldScriptRecordNode.h"

extern "C" void func_0208e000(WorldScriptRecordNode* destination,
                               const WorldScriptRecordNode* source)
{
    destination->key = source->key;
    destination->selector.rawSelector = source->selector.rawSelector;
    destination->opaque4 = source->opaque4;
    destination->next = source->next;
}
