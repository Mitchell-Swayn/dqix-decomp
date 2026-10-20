// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x210f3c0; symbol: data_0210f3c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {char* Actor_FindChoiceById(void*,int);void* memset(void*,int,unsigned);extern char SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/main @ 0x02054EF8; symbol: func_02054ef8; size: 0x44.
extern "C" int Memory_AllocateAndClearThreeWordRecord(void** p,SafeAllocator* a){if(!a)return 0;int* q=(int*)a->Allocate(12);*p=q;if(!q)return 0;q[0]=0;q[1]=0;q[2]=0;return 1;}
