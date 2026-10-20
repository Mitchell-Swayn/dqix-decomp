// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x210f3c0; symbol: data_0210f3c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {char* Actor_FindChoiceById(void*,int);void* memset(void*,int,unsigned);extern char SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/main @ 0x02079FC8; symbol: func_02079fc8; size: 0x4C.
extern "C" char* WorldRecordLookup_InitializeFourTriples(char* p){memset(p,0,12);memset(p+12,0,12);memset(p+24,0,12);memset(p+36,0,12);return p;}
