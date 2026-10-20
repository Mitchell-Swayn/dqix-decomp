#include <globaldefs.h>
ARM
extern "C" void InitializeType23LinkedNode(void*);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*, unsigned int);
struct Inner { unsigned char pad[0x6fc]; unsigned int list; unsigned char gap[0x400]; unsigned int node; };
// Original: arm9/ov017 @ 0x021B66B8; symbol: Object_AppendAndActivatePreparedNode; size: 0x38.
// Prepares the embedded node, appends it through the list at self+0x36fc, then sets its active byte at +0x1f.
extern "C" void Field_QueuePartyManagementWithReturnMode(unsigned char* self) {
    InitializeType23LinkedNode(*(void**)(self + 0x3b00));
    Inner* list = (Inner*)(self + 0x3000);
    LinkedQueue_AppendAndMarkActive((unsigned int*)list->list, list->node);
    (*(unsigned char**)(self + 0x3b00))[0x1f] = 1;
}
