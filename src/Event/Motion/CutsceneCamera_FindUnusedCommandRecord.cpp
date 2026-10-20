struct QueueNode { unsigned int active; unsigned char pad[0x44]; unsigned int link; };
struct Queue { QueueNode* nodes; int count; };
// Original: arm9/ov001 @ 0x02158D8C; symbol: func_ov001_02158d8c; size: 0x40.
extern "C" QueueNode* CutsceneCamera_FindUnusedCommandRecord(Queue* queue) { QueueNode* node=queue->nodes; for(int i=0;i<queue->count;i++,node=(QueueNode*)((unsigned char*)node+0x4c)) if(!node->active){node->link=0;return node;} return 0; }
