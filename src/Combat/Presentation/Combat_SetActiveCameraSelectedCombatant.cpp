#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned Combat_DispatchSelectionProcedure(...);
extern "C" unsigned GameState_ReadUnknownB0(...);
extern "C" unsigned BattleCamera_SetTrackedCombatant(...);
extern "C" unsigned Camera_GetObjectFlags(...);
extern "C" unsigned Combat_SetSelectionResult(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
// Original: arm9/ov025 @ 0x021e4f00; symbol: DispatchSelectionAndStoreCombatantField.
extern "C" int Combat_SetActiveCameraSelectedCombatant(char* p,int selection,int unused,int context){char* object=(char*)GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv());if(object){if(Camera_GetObjectFlags(object)&16){int result[8];if(Combat_DispatchSelectionProcedure(context,selection,B(p,8),result)!=1){Combat_SetSelectionResult(object,-1);return 1;}Combat_SetSelectionResult(object,result[0]);}else if(Camera_GetObjectFlags(object)&8){int result[8];if(Combat_DispatchSelectionProcedure(context,selection,B(p,8),result)!=1){BattleCamera_SetTrackedCombatant(object,-1);return 1;}BattleCamera_SetTrackedCombatant(object,result[0]);}}return 1;}
