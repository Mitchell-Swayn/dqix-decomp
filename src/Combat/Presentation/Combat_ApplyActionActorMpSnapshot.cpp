#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned BattleMenu_SetPartyCurrentMpAndBroadcast(...);
extern "C" unsigned BattleScene_GetMenuController(...);
extern "C" unsigned Combat_GetCommandActorSnapshot(...);
extern "C" unsigned BattleScene_GetActiveInstance(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState19GetCombatantByIndexEi(...);
// Original: arm9/ov025 @ 0x021e44fc; symbol: ApplyLinkedRecordHalfwordToCombatant.
extern "C" int Combat_ApplyActionActorMpSnapshot(void* unused,int index){char* record=(char*)Combat_GetCommandActorSnapshot(index,0);void* game=(void*)_ZN9GameState11GetInstanceEv();char* region=(char*)BattleScene_GetMenuController(BattleScene_GetActiveInstance());int slot=H(record,0x20);int valid=slot>=0&&slot<=3;int scan;if(valid){for(scan=0;scan<4;scan++){if(U(region+scan*0x448,0x9a4)==slot){scan=(int)(region+0x958+scan*0x448);goto found;}}}scan=0;found:char* entry=(char*)scan;char* object=(char*)_ZN9GameState19GetCombatantByIndexEi(game,slot);if(entry){unsigned short value=H(record,0x24);BattleMenu_SetPartyCurrentMpAndBroadcast(entry,value);H(entry,14)=value;}if(object)H((void*)U(object,0x130),6)=H(record,0x24);return 1;}
