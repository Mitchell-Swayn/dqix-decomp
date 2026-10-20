#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned Network_IsSessionActive(...);
extern "C" unsigned Object3D_InitializeExtendedMovementStateDefaults(...);
extern "C" unsigned Network_GetConnectionManager(...);
extern "C" unsigned ZoneState_GetTrackedZoneCache(...);
extern "C" unsigned Network_GetLocalMemberId(...);
extern "C" unsigned _ZN8Object3D10InitializeEv(...);
extern "C" unsigned _ZN8Object3D10MakeHiddenEv(...);
extern "C" unsigned _ZN8Object3D7DestroyEv(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState20GetGameObjectByIndexEi(...);
extern "C" unsigned _ZN9GameState27GetMaybeFieldMonsterByIndexEi(...);
// Original: arm9/ov017 @ 0x0219e014; symbol: GameState_ResetFieldMonsterGroupAndHideObjects; size: 0xd8.
struct Group {unsigned short unused;unsigned short index:2;unsigned short rest:14;};
extern "C" void GameState_ResetFieldMonsterGroupAndHideObjects(unsigned unused,unsigned group){
unsigned game=_ZN9GameState11GetInstanceEv();ZoneState_GetTrackedZoneCache();unsigned connection=Network_GetConnectionManager();if(group)for(int i=0;i<12;++i){unsigned object=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(game,i+(((Group*)group)->index*12+0x70));if(object){if(Network_IsSessionActive(connection)&&Network_GetLocalMemberId(connection)){Object3D_InitializeExtendedMovementStateDefaults(object);_ZN8Object3D10MakeHiddenEv(object);}else _ZN8Object3D7DestroyEv(object);}}
for(int i=7;i<=18;++i){unsigned object=_ZN9GameState20GetGameObjectByIndexEi(game,i);if(object){_ZN8Object3D10InitializeEv(object);_ZN8Object3D10MakeHiddenEv(object);}}
}