#include <globaldefs.h>
ARM
extern "C" void Combat_ResetSelectedCombatantComponentStates(char*);
extern "C" void BattleScene_CenterSelectedCombatantFormation(void*,void*,int);
extern "C" void BattleCamera_FrameObjectGroup(void*,void*,int,int);
extern "C" void Camera_StartShake(void*,int,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
// Original: arm9/ov025 @ 0x021DCE7C; symbol: LoadSpecialRecordAndConfigureComponentWordPair; size: 0x98.
extern "C" int BattleScene_ConfigureSpecialActionCamera(char* self,unsigned short* record,int value) {
 if(record){_ZN9GameState11GetInstanceEv();if(*record==781 || *record==582){int local=value;Combat_ResetSelectedCombatantComponentStates(self);BattleScene_CenterSelectedCombatantFormation(self,record,24);BattleCamera_FrameObjectGroup(self+0xc18,&local,1,1);Camera_StartShake(self+0xc18,409,2000);return 1;}}return 0;
}
