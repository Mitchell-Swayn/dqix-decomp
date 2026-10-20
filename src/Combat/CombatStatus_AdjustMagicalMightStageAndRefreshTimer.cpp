// Original ARM operations and callee behavior reviewed. Global reset target proven by original relocation.
// Original data: arm9/main @ 0x2114260; symbol: data_02114260.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void CombatStatus_ClearMagicalMightStage(void*);void* TextContext_GetSharedInstance(void*);void* TextWindow_GetChoiceResult(void*);void Graphics_WriteVRAMBankHControlByte(int);void LinkedQueue_InitializeNodeStatus(void*);void DisplaySpriteAnimation_ResetPlayback(void*);void* Network_GetConnectionManager();int Network_IsSessionActive(void*);int CombatantState_IsEligibleForLinkedCombatEffect(void*);void* memcpy(void*,const void*,unsigned);int Script_InitializeCountedDataView(void*,void*,int);extern char SoundCommandIncrementIndexedCounter_UnknownRoleZeroInitializedStorage[];}void ResetDMAChannel(int);struct Packed{unsigned low:12;signed int value:3;unsigned high:17;};struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};struct Record{int a,b;char c;char pad[3];};
// Original: arm9/main @ 0x02087B90; symbol: func_02087b90; size: 0x78.
extern "C" int CombatStatus_AdjustMagicalMightStageAndRefreshTimer(char* p,int add){Packed* q=(Packed*)(p+88);int v=q->value+add;if(v>2)v=2;if(v< -2)v=-2;if(!v){CombatStatus_ClearMagicalMightStage(p);return 0;}q->value=v;p[114]=5;p[149]=0;*(unsigned*)(p+20)|=0x4000;return q->value;}
