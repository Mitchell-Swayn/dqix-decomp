#include <globaldefs.h>
ARM
// Original: arm9/ov006:02158d50; Walks the linked list from object +0x2c until signed index reaches target times 16; returns that node or the original head if traversal ends first.
struct Node { unsigned char pad[0x1c]; Node* next; };
extern "C" Node* KrakPot_GetRecipePageHead(unsigned char* object, int target) {
    Node* node = *(Node**)(object + 0x2c);
    Node* result = node;
    short index = 0;
    short wanted = (short)(target << 4);
    while (node) {
        if (index == wanted) { result = node; break; }
        index = (short)(index + 1);
        node = node->next;
    }
    return result;
}
