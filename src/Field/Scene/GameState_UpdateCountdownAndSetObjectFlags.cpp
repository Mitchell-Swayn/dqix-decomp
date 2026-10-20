#include <globaldefs.h>
ARM
struct GameState;struct GameResources;struct MapGameObject;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* GameState_GetFieldOrbitCamera(GameState*);
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void GameObject_RequestMovementInputEnable();
extern "C" void GameResources_ClearSecondaryFlags(int,unsigned int);
extern "C" void Camera_EnableOrbitInput(void*);
extern "C" GameResources* GameResources_GetInstance();
// Original: arm9/ov017 @ 0x021BFE60; symbol: func_ov017_021bfe60; size: 0x88.
extern "C" int GameState_UpdateCountdownAndSetObjectFlags(unsigned char* p){
 void* gs=_ZN9GameState11GetInstanceEv();
 unsigned delta=_ZNK9GameState21GetEffectiveDeltaTimeEv(gs);
 if(delta<*(unsigned short*)(p+8)){*(unsigned short*)(p+8)-=delta;return 5;}
 *(unsigned short*)(p+8)=0;
 MapGameObject* obj=_ZN9GameState20GetUnknownGameObjectEv(gs);
 if(obj)GameObject_RequestMovementInputEnable();
 GameResources* res=GameResources_GetInstance();
 void* flagobj=GameState_GetFieldOrbitCamera((GameState*)gs);
 if(flagobj)Camera_EnableOrbitInput(flagobj);
 if(res)GameResources_ClearSecondaryFlags((int)res,0x80);
 *(unsigned short*)(p+8)=300;
 return 6;
}
