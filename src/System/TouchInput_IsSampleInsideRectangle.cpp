// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x210f3c0; symbol: data_0210f3c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {char* Actor_FindChoiceById(void*,int);void* memset(void*,int,unsigned);extern char SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/main @ 0x02012734; symbol: func_02012734; size: 0x4C.
extern "C" int TouchInput_IsSampleInsideRectangle(char* p,int x,int y,int width,int height){int a=*(unsigned short*)(p+32);int b=*(unsigned short*)(p+34);if(a<x)return 0;if(a>x+width)return 0;if(b<y)return 0;return b<=y+height;}
