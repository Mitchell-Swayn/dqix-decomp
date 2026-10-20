extern "C" { void *Network_GetCommandRecordPool(); int Network_IsOutgoingRecordQueueDrained(void *); int FindKeyInLockedNodeListOrFiveEntryState(void *, int); }
// Original: arm9/ov026 @ 0x021D8A40; symbol: func_ov026_021d8a40; size: 0x38.
extern "C" int BattleScene_IsPartyCommandSynchronizationReady() { void *state=Network_GetCommandRecordPool(); if(Network_IsOutgoingRecordQueueDrained(state)) return 1; return FindKeyInLockedNodeListOrFiveEntryState(state,99)==0; }
