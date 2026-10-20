#include <globaldefs.h>
ARM
extern "C" int StatusMenu_HasAvailablePartyMember(...);
extern "C" int StatusMenu_CycleAvailableVocation(...);
extern "C" int Menu_FindPageIndicatorByKey(...);
extern "C" int StatusMenu_SelectNextPartyMember(...);
extern "C" int StatusMenu_PopulateVocationStatsPage(...);
extern "C" int StatusMenu_PopulateVocationSpellsPage(...);
extern "C" int StatusMenu_PopulateLearnedAbilitiesPage(...);
extern "C" int StatusMenu_PopulatePassiveTraitsPage(...);
extern "C" int MenuTextCanvas_RefreshConfiguredFrameAndContents(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov004 @ 0x21707e8; symbol: data_ov004_021707e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov004 @ 0x021612EC; symbol: CycleEnabledIndexedFlagAndDispatchCurrentMode.
extern "C" int StatusMenu_SelectNextSubpage(int self){
if(*(signed char*)(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage+6)<=1)return 0;if(!StatusMenu_HasAvailablePartyMember(self,W(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,28))){StatusMenu_SelectNextPartyMember(self);return 0;}B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,11)=*(signed char*)(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage+11)+1;if(*(signed char*)(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage+6)<=*(signed char*)(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage+11))B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,11)=0;switch(B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,7)){case 100:B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,8)=StatusMenu_CycleAvailableVocation(self,W(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,28),B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,8),1);StatusMenu_PopulateVocationStatsPage(self);break;case 101:B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,8)=StatusMenu_CycleAvailableVocation(self,W(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,28),B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,8),1);StatusMenu_PopulateVocationSpellsPage(self);break;case 102:StatusMenu_PopulateLearnedAbilitiesPage(self);break;case 103:StatusMenu_PopulatePassiveTraitsPage(self);break;}int result=Menu_FindPageIndicatorByKey(self,3);MenuTextCanvas_RefreshConfiguredFrameAndContents(result,self);return 0;
}
