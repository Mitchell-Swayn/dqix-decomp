#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned GameState_GetObjectWithFlag100(...);
extern "C" unsigned CombatStatus_HasSleep(...);
extern "C" unsigned GameObject_IsDead(...);
extern "C" unsigned GameObject_GetCurrentVocationLevel(...);
extern "C" unsigned CombatEffect_TargetHasConfusion(...);
extern "C" unsigned CombatEffect_TargetHasParalysis(...);
extern "C" unsigned Combat_HasActionRestriction(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
// Original: arm9/ov024 @ 0x021eb1ec; symbol: TestAndConsumeCombatantActionRestrictions.
extern "C" int Combat_CanRollPostActionActivation(void* unused,int index){char* object=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);if(!object)return 0;char* nested=(char*)U(object,0x138);if(B(nested,0x3a)){B(nested,0x3a)=0;return 0;}if(GameObject_GetCurrentVocationLevel(object)<10U)return 0;if(Combat_HasActionRestriction(object))return 0;if(CombatEffect_TargetHasParalysis(object))return 0;if(CombatEffect_TargetHasConfusion(object))return 0;if(CombatStatus_HasSleep((void*)U(object,0x138)))return 0;if(GameObject_IsDead(object))return 0;return (((unsigned)B((void*)U(object,0x138),0x3b)<<28)>>31)==0;}
