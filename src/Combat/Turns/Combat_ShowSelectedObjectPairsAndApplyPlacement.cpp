#include <globaldefs.h>
ARM
struct Eight {short values[8];};struct Triple {int x,y,z;};
extern "C" char* _ZN9GameState11GetInstanceEv(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(...);
extern "C" int _ZN8Object3D11MakeVisibleEv(...);
extern "C" int Field_ApplyMemberWeaponAttachmentVariant(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x021639B4; symbol: Combat_ShowSelectedObjectPairsAndApplyPlacement; size: 0xc8.
// Combat ShowSelectedObjectPairsAndApplyPlacement from listed field operations and calls.
extern "C" void Combat_ShowSelectedObjectPairsAndApplyPlacement(char* self){void* game=_ZN9GameState11GetInstanceEv();short indices[4];int count=Combat_CollectEligiblePartyIds(P(self,0x29c),indices,4,0);for(int i=0;i<count;++i){char* object=_ZN9GameState20GetGameObjectByIndexEi(game,indices[i]*(short)12+28);if(object&&S(object,2)>=0)_ZN8Object3D11MakeVisibleEv(object);object=_ZN9GameState20GetGameObjectByIndexEi(game,indices[i]*(short)12+29);if(object&&S(object,2)>=0)_ZN8Object3D11MakeVisibleEv(object);Field_ApplyMemberWeaponAttachmentVariant(indices[i],1);}}
