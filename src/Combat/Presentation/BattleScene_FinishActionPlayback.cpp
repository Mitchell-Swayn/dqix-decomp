#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct MotionState {unsigned char unknown[0xc1]; unsigned char low:4,mode:4;};
extern "C" {
int Combat_CollectEligiblePartyIds(void*,short*,int,int);
int Combat_CollectPresentEnemyIndices(void*,short*,int,int);
void CombatantMotion_SetSavedActionDescriptor(int,unsigned);
void BattleCombo_RequestIndicatorExit(void*,int);
void Field_LatchSessionTransition(void*);
unsigned TextContext_GetSharedInstance();
}
// Original: arm9/ov025 @ 0x021DB7F8; symbol: BattleScene_FinishActionPlayback; size: 0xE0.
extern "C" void BattleScene_FinishActionPlayback(unsigned char* self){
GameState* state=GameState::GetInstance();short ids[16];int count=0;
count+=Combat_CollectEligiblePartyIds(*(void**)(self+0x29c),ids,16,count);
count+=Combat_CollectPresentEnemyIndices(*(void**)(self+0x29c),ids+count,16-count,0);
short* cursor=ids;for(int i=0;i<count;++i,++cursor){GameObject* object=state->GetCombatantByIndex(*cursor);if(object){MotionState* motion=(MotionState*)object;unsigned mode=motion->mode;if(mode==1||mode==6)motion->mode=0;CombatantMotion_SetSavedActionDescriptor((int)object,0);}}
BattleCombo_RequestIndicatorExit(self+0x6ffc,1);
Field_LatchSessionTransition(GameResources_GetInstance());
*(unsigned char*)(TextContext_GetSharedInstance()+0x19be)=0;
self[0xe90]=0;*(unsigned*)(self+0xe94)=0;
}
