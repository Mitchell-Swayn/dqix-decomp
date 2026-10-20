struct PoolNode { unsigned int active; unsigned char pad[0x38]; unsigned int link; };
struct Pool { PoolNode* nodes; int count; };
// Original: arm9/ov001 @ 0x02159EB0; symbol: func_ov001_02159eb0; size: 0x40.
extern "C" PoolNode* Event_FindUnusedMotionCommand(Pool* pool) { PoolNode* node=pool->nodes; for(int i=0;i<pool->count;i++,node=(PoolNode*)((unsigned char*)node+0x40)) if(!node->active){node->link=0;return node;} return 0; }
