// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x210f3c0; symbol: data_0210f3c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {char* Actor_FindChoiceById(void*,int);void* memset(void*,int,unsigned);extern char SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/main @ 0x02072A28; symbol: func_02072a28; size: 0x40.
extern "C" void MessageTextTable_AppendTextEntry(char* p,char* in){short i=*(short*)(p+6);if(*(short*)(p+4)<=i)return;char* q=*(char**)p+i*8;*(short*)q=*(short*)in;*(int*)(q+4)=*(int*)(in+4);++*(short*)(p+6);}
