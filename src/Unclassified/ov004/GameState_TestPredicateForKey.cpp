extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
// Original: arm9/ov004 @ 0x0215F74C; symbol: func_ov004_0215f74c; size: 0x24.
extern "C" int GameState_TestPredicateForKey(int unused,int key) { return GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),key)!=0; }
