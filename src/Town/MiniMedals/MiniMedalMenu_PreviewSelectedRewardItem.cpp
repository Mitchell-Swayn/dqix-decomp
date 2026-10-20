#include <globaldefs.h>
ARM
struct State;
// Original data: arm9/ov004 @ 0x216fffa; symbol: data_ov004_0216fffa.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 674605000156080040560a005b560f003c5614001243.
// Observed span: 22 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" {void Menu_QueueScriptEntry(State*,unsigned);void* Menu_GetDisplayRecordRegistry(State*);void* MenuRecordList_LocateByKey(void*,unsigned);unsigned MenuRecord_GetType(void*);unsigned Menu_GetSelectedGridIndex(unsigned short*);void MenuBackground_SelectStateRecord(void*,int);extern short MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes_Variant2[];}
// Original: arm9/ov004 @ 0x02168290; symbol: func_ov004_02168290; size: 0x88.
extern "C" int MiniMedalMenu_PreviewSelectedRewardItem(State* p){
void* a=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(p),7);
if(a && MenuRecord_GetType(a)==16){
void* b=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(p),14);
if(!b)return 0;
if(MenuRecord_GetType(b)!=7)return 0;
unsigned index=Menu_GetSelectedGridIndex((unsigned short*)b);
MenuBackground_SelectStateRecord(a,MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes_Variant2[index*2]);
}
Menu_QueueScriptEntry(p,0x68);
return 0;
}
