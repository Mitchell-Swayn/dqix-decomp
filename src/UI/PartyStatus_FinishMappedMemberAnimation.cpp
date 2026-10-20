#pragma optimize_for_size off
#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20fdc60; symbol: data_020fdc60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Entry { unsigned char bytes[20]; };extern "C" Entry PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage[4];extern "C" void PartyStatus_RequestPanelSlideOut(Entry*,int);
// Original: arm9/main @ 0x02027304; symbol: func_02027304; size: 0x88.
extern "C" void PartyStatus_FinishMappedMemberAnimation(unsigned char* object,int wanted) {if(wanted<0){for(int i=0;i<4;++i)PartyStatus_RequestPanelSlideOut(PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage+i,0);return;}if(wanted>=4)return;for(int i=0;i<4;i++)if(wanted==(object+i)[0x758]){PartyStatus_RequestPanelSlideOut(PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage+i,0);return;}}
