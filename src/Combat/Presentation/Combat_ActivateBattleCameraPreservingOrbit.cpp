#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Triple{int x,y,z;};extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* BattleScene_GetActiveInstance();extern "C" char* GameState_ReadUnknownB0(void*);extern "C" void* BattleScene_GetCamera(void*);extern "C" void GameState_SetUnknown3b0(void*,void*);extern "C" void BattleCamera_ResetShotAndTransitions(void*,int,int,int);extern "C" void _ZN8Vector3iaSERKS_(void*,const Triple*);extern "C" void Camera_SetOrbitParameters(void*,const Triple*);
// Original: arm9/ov025 @ 0x021E4E10; symbol: SwitchGameStateObjectPreservingPositionVectors; size: 0x9c.
extern "C" int Combat_ActivateBattleCameraPreservingOrbit(void){
void* state=_ZN9GameState11GetInstanceEv();void* control=BattleScene_GetActiveInstance();char* old=GameState_ReadUnknownB0(state);Triple first=*(Triple*)(old+16);Triple second=*(Triple*)(old+112);void* object=BattleScene_GetCamera(control);GameState_SetUnknown3b0(state,object);BattleCamera_ResetShotAndTransitions(object,1,1,1);char* current=GameState_ReadUnknownB0(state);_ZN8Vector3iaSERKS_(current+16,&first);Camera_SetOrbitParameters(current,&second);return 1;
}
