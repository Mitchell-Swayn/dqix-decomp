#include "World/WorldScriptRecordNode.h"

// Original: arm9/main @ 0x0208E06C; symbol: func_0208e06c; size: 0x3C.
extern "C" WorldScriptRecordNode* WorldScriptRecordList_FindNodeByNonnegativeKey(
    WorldScriptRecordNode** head, int key)
{
    if (key < 0) return 0;
    WorldScriptRecordNode* node = *head;
    if (node == 0) return 0;
    goto checkNode;
findNode:
    if (node->key == key) return node;
    node = node->next;
checkNode:
    if (node != 0) goto findNode;
    return node;
}
