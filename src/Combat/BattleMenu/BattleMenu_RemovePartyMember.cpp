#include <globaldefs.h>
ARM
extern "C" int Graphics_ResetAndApplyGlobalConfiguration(...);
extern "C" int BattleMenu_ResetMemberCommandState(...);
extern "C" int GameState_CopyIndexedObjectHalfwordFields(...);
extern "C" int BattleMenu_UpdateMemberRowPositions(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
// Original data: arm9/ov000 @ 0x2183ff0; symbol: data_ov000_02183ff0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" int BattleMenuRemovePartyMember_UnknownRoleInitializedBytes;
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x02174A50; symbol: ResetMatchingPartyRecordAndDecrementSharedCount; size: 0xc4.
extern "C" void BattleMenu_RemovePartyMember(char* self,int index){
int valid=(index>=0&&index<=3);if(!valid)return;char* base=self+0x958;for(int i=0;i<4;i++){char* entry=base+*(signed char*)(self+i+0x6c)*0x448;if(index==W(entry,76)){Graphics_ResetAndApplyGlobalConfiguration(entry+80);Graphics_ResetAndApplyGlobalConfiguration(entry+104);BattleMenu_ResetMemberCommandState(entry+8);GameState_CopyIndexedObjectHalfwordFields(entry,-1,0);BattleMenuRemovePartyMember_UnknownRoleInitializedBytes--;BattleMenu_UpdateMemberRowPositions(self);if(BattleMenuRemovePartyMember_UnknownRoleInitializedBytes<=0)BattleMenuRemovePartyMember_UnknownRoleInitializedBytes=1;return;}}
}
