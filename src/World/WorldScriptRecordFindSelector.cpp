#include "World/WorldScriptRecordNode.h"

extern "C" WorldScriptRecordNode* func_0208e024(
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
