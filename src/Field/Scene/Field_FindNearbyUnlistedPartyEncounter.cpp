#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned char* _ZN9GameState20GetUnknownGameObjectEv(void*);unsigned char* GameState_GetIndexList(void*);void __clear(void*,unsigned);unsigned char* GameState_GetObjectWithFlag100(void*,int);unsigned short _ZNK8Object3D10GetField06Ev(void*);int Graphics_TestNonzeroDistanceWithinCombinedRadii(unsigned,unsigned,int);}
// Original: arm9/ov017 @ 0x021971C4; symbol: GameState_FindNearbyUnlistedObjectIdentifier; size: 0x108.
// Finds nearby unlisted mode2 object sharing leader field06 and differing from stored identifier.
extern "C" unsigned Field_FindNearbyUnlistedPartyEncounter(unsigned char* self){void* game=_ZN9GameState11GetInstanceEv();if(!game)return 0;unsigned char* leader=_ZN9GameState20GetUnknownGameObjectEv(game);if(!leader)return 0;unsigned char* inventory=GameState_GetIndexList(game);int listed[4];unsigned result=0;__clear(listed,16);for(int i=0;i<inventory[0xf7c];++i)listed[(inventory+i)[0xf78]]=1;for(int i=0;i<4;++i){if(listed[i])continue;unsigned char* object=GameState_GetObjectWithFlag100(game,i);if(!object)continue;unsigned first=_ZNK8Object3D10GetField06Ev(object);if(first==_ZNK8Object3D10GetField06Ev(leader)&&object[0xbe]==2&&Graphics_TestNonzeroDistanceWithinCombinedRadii((unsigned)leader,(unsigned)object,4096)){unsigned id=U(object,0x1b2);if(U(self,0x44c2)!=id){result=id;break;}}}return result;}
