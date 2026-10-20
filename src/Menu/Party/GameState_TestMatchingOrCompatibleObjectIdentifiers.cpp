#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv(),*GameState_GetObjectWithFlag100(void*,int);extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
// Original: arm9/ov002 @ 0x02154a6c; symbol: GameState_TestMatchingOrCompatibleObjectIdentifiers; size 0x128.
extern "C" int GameState_TestMatchingOrCompatibleObjectIdentifiers(int unused,int first,int second){void* game=_ZN9GameState11GetInstanceEv();void* a=GameState_GetObjectWithFlag100(game,first);if(!a)return 0;void* b=GameState_GetObjectWithFlag100(game,second);if(!b)return 0;unsigned short id=_ZNK8Object3D10GetField06Ev(a);if(id==_ZNK8Object3D10GetField06Ev(b))return 1;if((_ZNK8Object3D10GetField06Ev(a)==10000&&_ZNK8Object3D10GetField06Ev(b)==5900)||(_ZNK8Object3D10GetField06Ev(a)==5900&&_ZNK8Object3D10GetField06Ev(b)==10000))return 1;if((_ZNK8Object3D10GetField06Ev(a)==10100&&_ZNK8Object3D10GetField06Ev(b)==6401)||(_ZNK8Object3D10GetField06Ev(a)==6401&&_ZNK8Object3D10GetField06Ev(b)==10100))return 1;return 0;}
