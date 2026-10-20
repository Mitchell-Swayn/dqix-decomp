#include <globaldefs.h>
ARM
struct Source { int pad[2]; unsigned int enabled:1; unsigned int value:15; unsigned int fixed:1; unsigned int hasOther:1; unsigned int unused:14; unsigned int other:15; unsigned int remaining:17; };
struct Global { int pad[3]; unsigned char* object; };
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" Global CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov025 @ 0x021E5F54; symbol: func_ov025_021e5f54; size: 0x9C.
extern "C" int Combat_ConfigurePackedPresentationParameters(Source* source) {
if(source->enabled)*(short*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.object+0x21c)=source->value;
else *(short*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.object+0x21c)=0;
if(source->fixed)*(short*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.object+0x220)=30;
else *(short*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.object+0x220)=-1;
if(source->hasOther)*(short*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.object+0x222)=source->other;
else *(short*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.object+0x222)=-1;
return 1;
}
