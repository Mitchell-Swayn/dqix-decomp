#include <globaldefs.h>
ARM
struct GameState;struct GameResources;struct MapGameObject;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* GameState_GetField3B0ObjectWithFlag4(GameState*);
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void SetByteFieldAtOffset253ToOne();
extern "C" void ClearWordAtOffset4MaskedBits(int,unsigned int);
extern "C" void Object_SetWordAtOffset23CTo1(void*);
extern "C" GameResources* GameResources_GetInstance();
// Original: arm9/ov017 @ 0x021BFE60; symbol: func_ov017_021bfe60; size: 0x88.
extern "C" int GameState_UpdateCountdownAndSetObjectFlags(unsigned char* p){
 void* gs=_ZN9GameState11GetInstanceEv();
 unsigned delta=_ZNK9GameState21GetEffectiveDeltaTimeEv(gs);
 if(delta<*(unsigned short*)(p+8)){*(unsigned short*)(p+8)-=delta;return 5;}
 *(unsigned short*)(p+8)=0;
 MapGameObject* obj=_ZN9GameState20GetUnknownGameObjectEv(gs);
 if(obj)SetByteFieldAtOffset253ToOne();
 GameResources* res=GameResources_GetInstance();
 void* flagobj=GameState_GetField3B0ObjectWithFlag4((GameState*)gs);
 if(flagobj)Object_SetWordAtOffset23CTo1(flagobj);
 if(res)ClearWordAtOffset4MaskedBits((int)res,0x80);
 *(unsigned short*)(p+8)=300;
 return 6;
}
