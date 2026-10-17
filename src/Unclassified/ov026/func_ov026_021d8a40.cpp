extern "C" { void *ReadGlobalAt02100044(); int TestQueueAndFiveItemSentinels(void *); int FindKeyInLockedNodeListOrFiveEntryState(void *, int); }
// Original: arm9/ov026 @ 0x021D8A40; symbol: func_ov026_021d8a40; size: 0x38.
extern "C" int func_ov026_021d8a40() { void *state=ReadGlobalAt02100044(); if(TestQueueAndFiveItemSentinels(state)) return 1; return FindKeyInLockedNodeListOrFiveEntryState(state,99)==0; }
