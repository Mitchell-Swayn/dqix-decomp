#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct SignedThree{signed value:3;unsigned other:29;};
extern "C" unsigned GameState_GetObjectWithFlag100(...);
extern "C" unsigned GameObject_GetLinkedIndexedState(...);
extern "C" unsigned CombatantMotion_SetPrimaryTargetIndex(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState19GetCombatantByIndexEi(...);
// Original: arm9/ov025 @ 0x021dfbfc; symbol: ApplyLinkedModeByteAcrossRecordGroups.
extern "C" void BattleScene_AssignCommandPrimaryTargets(char* p){void* game=(void*)_ZN9GameState11GetInstanceEv();char* owner=(char*)U(p,0x29c);char* base=owner+0x21c;base+=0x8000;for(int i=0;i<(int)U(owner,0x8e24);i++){char* group=base+i*40;char* entry=(char*)U(group,16);while(entry){int id=H(entry,0x20);int apply=0;int special=id>=192&&id<=199;if(special)apply=1;else{void* object=(void*)GameState_GetObjectWithFlag100(game,id);if(object){char* state=(char*)GameObject_GetLinkedIndexedState(object);if(state&&(signed char)U(state,0x94c)!=5)apply=1;}}if(apply){void* object=(void*)_ZN9GameState19GetCombatantByIndexEi(game,id);if(object){char* linked=(char*)U(group,20);if(linked)CombatantMotion_SetPrimaryTargetIndex(object,(unsigned char)*(short*)(linked+14));}}entry=(char*)U(entry,0x30);}}}
