#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2183ff0; symbol: data_ov000_02183ff0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
// Original data: arm9/ov000 @ 0x2184288; symbol: data_ov000_02184288.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" {char* BattleMenu_GetSelectedPartyCommandRecord(char*);void BattleMenu_OpenPartyCommandPanel(void*,void*,unsigned,unsigned);void BattleMenu_ResetPartyCommandSelection(void*);void BattleMenu_OpenMemberCommandGrid(void*,int);extern unsigned BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[];extern unsigned BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov000 @ 0x02174D08; symbol: DispatchSelectedRecordFlagsTwoAndFour; size: 0x9c.
// Dispatches selected record flag2 or4 updates and clears processed flag4.
extern "C" void BattleMenu_ProcessPendingCommandMenuRefresh(char* self){unsigned flags=*(unsigned short*)(self+0x1d72);if(flags&2){char* entry=BattleMenu_GetSelectedPartyCommandRecord(self);BattleMenu_OpenPartyCommandPanel(self,entry,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[0],BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);return;}if(flags&4){char* entry=BattleMenu_GetSelectedPartyCommandRecord(self);if(!entry)return;int mode=*(int*)(self+0x118)==2;BattleMenu_ResetPartyCommandSelection(entry);if(*(int*)(entry+0x38))BattleMenu_OpenMemberCommandGrid(entry,mode);*(unsigned short*)(self+0x1d72)&=~4;}}
