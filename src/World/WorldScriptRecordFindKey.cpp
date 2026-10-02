#include "World/WorldScriptRecordNode.h"

extern "C" WorldScriptRecordNode* func_0208e06c(
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
