#include <globaldefs.h>
ARM
extern "C" { typedef void WfcTaskCallback(void*, void*); }
#pragma force_active on
struct TaskNode { TaskNode* previous; TaskNode* next; WfcTaskCallback* callback; void* context; };
struct TaskQueue {
    void* freeNodes; void* removedNodes; unsigned padding[2];
    TaskNode activeHead; TaskNode activeEnd; unsigned padding30; int removals; unsigned char enabled; unsigned char padding39[7];
};
extern "C" {
// Original data: arm9/ov031 @ 0x02290d9c; symbol: data_ov031_02290d9c; initially-zero pointer to 0x40-byte queues.
extern TaskQueue* WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage;
void* WfcUtility_PopPointerRingBack(void*);
void Overlay_RemoveIndexedPointerPair(unsigned,void*);
}
// Original: arm9/ov031 @ 0x0223e168; symbol: func_ov031_0223e168; size: 0xb0.
// Runs each enabled queue's callbacks, then drains its deferred task-removal ring.
extern "C" void WfcUtility_RunTaskQueue(unsigned index)
{
    if (!WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage[index].enabled) return;
    TaskNode* node=WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage[index].activeHead.previous;
    while (node != &WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage[index].activeEnd) {
        node->callback(node,node->context);
        node=node->next;
    }
    for (int i=0;i<WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage[index].removals;++i) {
        void* removed=WfcUtility_PopPointerRingBack(WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage[index].removedNodes);
        if (!removed) return;
        Overlay_RemoveIndexedPointerPair(index,removed);
    }
}

#pragma force_active reset
