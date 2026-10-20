#include <globaldefs.h>
ARM
struct Node { unsigned char pad[0x1c]; Node* next; };
// Original: arm9/ov006 @ 0x02158CFC; symbol: func_ov006_02158cfc; size: 0x54.
extern "C" void Util_FindNodeAndUpdateSixteenEntryAnchor(void* self, Node* target) {
    Node* node = *(Node**)((char*)self + 0x2c);
    Node* anchor = node;
    signed char count = 0;
    while (node != 0) {
        if (count % 16 == 0) {
            anchor = node;
            count = 0;
        }
        if (node == target) break;
        count = (signed char)(count + 1);
        node = node->next;
    }
    *(Node**)((char*)self + 0x30) = anchor;
}
