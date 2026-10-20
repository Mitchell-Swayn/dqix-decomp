#include <globaldefs.h>
ARM
#pragma always_inline on
struct Placement;
namespace {
// Four copied words: packed actor/duration followed by three position or turn components.
struct MotionTaskPayload { unsigned words[4]; };
struct MotionTask { unsigned kind, delay; MotionTaskPayload payload; MotionTask* next; };
struct MotionTaskQueue { unsigned char prefix[0xe0]; MotionTask* pending; MotionTask* available; };
}
#pragma force_active on
// Original: arm9/ov025 @ 0x021EEE48; symbol: func_ov025_021eee48; size: 0x58.
// Copies a placement task into the next available node and pushes it onto the pending list.
extern "C" void Combat_QueueMovementOrTurnTask(void* object, Placement* placement)
{
    MotionTaskQueue* queue = (MotionTaskQueue*)object;
    MotionTask* record = queue->available;
    const MotionTask* input = (const MotionTask*)placement;
    if (!record) return;
    MotionTask* next = record->next;
    record->kind = input->kind;
    record->delay = input->delay;
    record->payload = input->payload;
    record->next = input->next;
    queue->available = next;
    record->next = queue->pending;
    queue->pending = record;
}
#pragma force_active reset
