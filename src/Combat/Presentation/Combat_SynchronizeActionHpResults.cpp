#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* BattleScene_GetActiveInstance();extern "C" char* BattleScene_ResolveCurrentActionRecord(void*);extern "C" void* BattleScene_GetOverrideActionCommand(void*);extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* BattleScene_GetMenuController(void*);extern "C" char* BattleMenu_FindPartyPanelByCombatantIndex(void*,int);extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);extern "C" void BattleMenu_SetPartyCurrentHpAndBroadcast(void*,unsigned);
// Original: arm9/ov025 @ 0x021E9EDC; symbol: SynchronizeLinkedCombatantHalfwordValues; size: 0xE8.
extern "C" void Combat_SynchronizeActionHpResults(void){void* state=BattleScene_GetActiveInstance();char* record=BattleScene_ResolveCurrentActionRecord(state);if(BattleScene_GetOverrideActionCommand(state))return;void* game=_ZN9GameState11GetInstanceEv();void* region=BattleScene_GetMenuController(BattleScene_GetActiveInstance());char* node=P(record,16);const int one=1;while(node){int index=U(node,32);unsigned short value=U(node,34);char* target=BattleMenu_FindPartyPanelByCombatantIndex(region,index);char* object=_ZN9GameState19GetCombatantByIndexEi(game,index);if(object){int party;if(index>=0&&index<=3)party=one;else party=0;if(party!=0){value=U(node,34);target=BattleMenu_FindPartyPanelByCombatantIndex(region,index);object=_ZN9GameState19GetCombatantByIndexEi(game,index);}if(target&&object){BattleMenu_SetPartyCurrentHpAndBroadcast(target,value);U(target,12)=value;U(P(object,0x130),4)=value;}}node=P(node,0x30);}}
