#include <globaldefs.h>
ARM
struct Interface { virtual void Before(); virtual void Execute(); };
// Original: arm9/ov023 @ 0x021F698C; symbol: Object_InvokeSecondVirtualOnLinkedNodes; size: 0x2C.
// Walks the linked nodes from *head, invokes vtable slot 1 on each, and follows the link at +0x18.
extern "C" void MenuRecordList_InvokeSecondaryPass(void **head) {
    Interface *node = (Interface *)*head;
    while (node) {
        node->Execute();
        node = *(Interface **)((unsigned char *)node + 0x18);
    }
}
