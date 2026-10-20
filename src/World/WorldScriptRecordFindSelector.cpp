#include "World/WorldScriptRecordNode.h"

// Original: arm9/main @ 0x0208E024; symbol: func_0208e024; size: 0x48.
extern "C" WorldScriptRecordNode* WorldScriptRecordNode_FindNthSelectorMatch(
    WorldScriptRecordNode** head, int selector, int occurrence)
{
    WorldScriptRecordNode* node = *head;
    if (node == 0) return 0;
    unsigned char matches = 0;
    while (node != 0)
    {
        if (node->selector.selectorBits.selectorValue == selector)
        {
            if (matches == occurrence) return node;
            matches = (unsigned char)(matches + 1);
        }
        node = node->next;
    }
    return node;
}
