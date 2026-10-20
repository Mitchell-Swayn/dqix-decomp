#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void* parameter);
extern "C" void* ActorPool_GetGlobalInstance();
extern "C" unsigned* ActorPool_GetActiveSlot(unsigned** container,unsigned value);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215D08C; symbol: CopyScriptIndexedValue; size: 0x68.
// Reads two script indices, resolves their shared entries, and copies a nonzero source value into the bounded slot.
extern "C" int Script_SetActorBoundObject(void* parameter){int a=Script_ReadParameterAsInteger(parameter);int b=Script_ReadParameterAsInteger((char*)parameter+8);unsigned** c=(unsigned**)ActorPool_GetGlobalInstance();unsigned* slot=ActorPool_GetActiveSlot(c,*(unsigned*)((char*)*(unsigned**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4)+a*16+4));if(!slot)return 0;unsigned v=*(unsigned*)((char*)*(unsigned**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4)+b*16+12);if(!v)return 0;((unsigned*)slot)[4]=v;return 1;}
