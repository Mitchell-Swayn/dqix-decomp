#include <globaldefs.h>
struct QueueNode;struct Queue;
extern "C" QueueNode* Queue_AllocateAndAppendNode(Queue* queue);
extern "C" void* memcpy(void* destination, const void* source, unsigned length);
// Original: arm9/ov001 @ 0x021591D0; symbol: func_ov001_021591d0; size: 0x40.
// Appends a type-16 queue node, copies three input words, and stores the trailing index word.
extern "C" void CutsceneCamera_QueueEyeAndTargetShake(void* queue, unsigned first, unsigned second, unsigned third, unsigned index) {
    unsigned char* node = (unsigned char*)Queue_AllocateAndAppendNode((Queue*)queue);
    if (!node) return;
    *(unsigned*)node = 0x10;
    memcpy(node + 4, &first, 12);
    *(unsigned*)(node + 0x1c) = index;
}
