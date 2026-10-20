#include <globaldefs.h>
// Original data: arm9/main @ 0x20fdc60; symbol: data_020fdc60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Entry {unsigned short unknown;unsigned char flags;char pad[17];};extern "C" Entry PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage[4];
// Original: arm9/main @ 0x0202738C; symbol: func_0202738c; size: 0xAC.
extern "C" void PartyStatus_SetMappedMemberAnimationFlags(char* self,int enabled,unsigned char mask,int wanted) {if(wanted<0){Entry* entry;for(int i=0;i<4;++i){entry=PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage+i;unsigned flags=entry->flags;if(enabled)flags|=mask;else flags &= ~mask;entry->flags=flags;}return;}if(wanted>=4)return;for(int i=0;i<4;++i){Entry* entry=PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage+i;if(wanted==(unsigned char)(self+i)[0x758]){if(enabled){entry->flags|=mask;return;}else {entry->flags &=~mask;return;}}}}
