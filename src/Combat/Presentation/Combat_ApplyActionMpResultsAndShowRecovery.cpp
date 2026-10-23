// Original: arm9/ov025 @ 0x021E9D14; symbol: Combat_ApplyActionMpResultsAndShowRecovery; size: 0x1C8.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
ARM
struct Position{int xyz[3];};struct State {unsigned char first,pad[15],enabled;unsigned char a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1;short unused,v1,v2,v3,v4,palette,pad2;unsigned values[12];};
#pragma always_inline on
inline int IsParty(int n){return n>=0&&n<=3;}
extern "C" {
unsigned BattleScene_GetActiveInstance();char* BattleScene_ResolveCurrentActionRecord(char*);
void* BattleScene_GetOverrideActionCommand(void*);void* BattleScene_GetMenuController(unsigned char*);
void* Util_GetNestedListNodeAtIndex(void*,int,int);
char* BattleMenu_FindPartyPanelByCombatantIndex(void*,int);
void* ZoneContainer_GetGlobalRenderParts();void FloatingNumber_EnqueueValue(char*,int,const int*,unsigned char,unsigned,unsigned);
void* Object_GetGlobalSixteenEntryDisplayState();void Object_InitializeRenderValuesAndUnitScales(State*);
int ObjectPool_SpawnFromTemplateKey(void*,int,void*);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void BattleMenu_SetPartyCurrentMpAndBroadcast(void*,int);
extern char Main_UnknownRoleZeroInitializedStorage[];
}
extern "C" void Combat_ApplyActionMpResultsAndShowRecovery(void* unused){
char* scene=(char*)BattleScene_GetActiveInstance();char* action=BattleScene_ResolveCurrentActionRecord(scene);if(BattleScene_GetOverrideActionCommand(scene))return;
GameState* game=GameState::GetInstance();void* menu=BattleScene_GetMenuController((unsigned char*)BattleScene_GetActiveInstance());char* record=*(char**)(action+0x10);if(Util_GetNestedListNodeAtIndex(record,0,5))return;
for(;record;record=*(char**)(record+0x30)){
int member=*(unsigned short*)(record+0x20);unsigned short mp=*(unsigned short*)(record+0x24);char* panel=BattleMenu_FindPartyPanelByCombatantIndex(menu,member);char* object=(char*)game->GetCombatantByIndex(member);if(!object)continue;
char* result=*(char**)(record+0x14);if(result){int amount=-*(short*)(result+0xc);if(amount>0){char* parts=(char*)ZoneContainer_GetGlobalRenderParts();Position pos=*(Position*)(object+0x44);pos.xyz[1]+=((Object3D*)object)->GetHeight();FloatingNumber_EnqueueValue(parts,amount,pos.xyz,3,0,0);void* pool=Object_GetGlobalSixteenEntryDisplayState();State values;Object_InitializeRenderValuesAndUnitScales(&values);values.values[4]+=((Object3D*)object)->GetHeight()/2;values.v1=member;ObjectPool_SpawnFromTemplateKey(pool,16,&values);SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,101,0);}}
if(!IsParty(member)&&*(void**)(record+0x14)){member=*(short*)(record+0x1c);mp=*(unsigned short*)(record+0x1e);panel=BattleMenu_FindPartyPanelByCombatantIndex(menu,member);object=(char*)game->GetCombatantByIndex(*(short*)(record+0x1c));}
if(panel&&object){BattleMenu_SetPartyCurrentMpAndBroadcast(panel,mp);*(unsigned short*)(panel+0xe)=mp;*(unsigned short*)(*(char**)(object+0x130)+6)=mp;}
}
}
