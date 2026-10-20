#include "World/WorldScriptRecordNode.h"

// Original: arm9/main @ 0x0208E000; symbol: func_0208e000; size: 0x24.
extern "C" void WorldScriptRecordNode_Copy(WorldScriptRecordNode* destination,
                               const WorldScriptRecordNode* source)
{
    destination->key = source->key;
    destination->selector.rawSelector = source->selector.rawSelector;
    destination->opaque4 = source->opaque4;
    destination->next = source->next;
}
