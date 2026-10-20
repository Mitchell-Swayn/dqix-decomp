#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" void* Combat_GetCurrentPresentationAllocator(char*);
extern "C" int BackgroundLoader_QueueResolvedPathWithSingleFence(char*);
extern "C" void Combat_TrackPresentationLoadTask(unsigned char*,int);
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];extern "C" const char Combat_QueueActorCheerArchive_PathDataCharaCsOuenChr[];
// Original: arm9/ov025 @ 0x021E8344; symbol: AppendBitSelectedFormattedResourceIndex; size: 0x80.
extern "C" int Combat_QueueActorCheerArchive(int unused,char* self){
char text[80];_ZN16BackgroundLoader11GetInstanceEv();Combat_GetCurrentPresentationAllocator(*(char**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage+12));char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),*(unsigned short*)(*(char**)(self+16)+32));int code=109;struct Bits{unsigned char gender:1;unsigned char rest:7;};if(((Bits*)(*(char**)(object+0x150)+0x49c))->gender==1)code=119;sprintf(text,Combat_QueueActorCheerArchive_PathDataCharaCsOuenChr,code);int value=BackgroundLoader_QueueResolvedPathWithSingleFence(text);Combat_TrackPresentationLoadTask(*(unsigned char**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage+12),value);return 1;
}
