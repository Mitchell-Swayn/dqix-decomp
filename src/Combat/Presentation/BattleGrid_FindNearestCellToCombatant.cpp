#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Pair{int x,y;};struct Vec{int x,y,z;};extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);extern "C" Pair BattleGrid_GetCellCoordinates(int*);extern "C" void __clear(void*,unsigned);extern "C" int Vector3fix_Distance(const Vec*,const Vec*);
// Original: arm9/ov025 @ 0x021E1540; symbol: FindNearestPlanarGridEntryAmongEightyOne; size: 0xDC.
extern "C" unsigned char BattleGrid_FindNearestCellToCombatant(int index){char* object=_ZN9GameState20GetGameObjectByIndexEi(_ZN9GameState11GetInstanceEv(),index);int best=0;if(object){Vec position=*(Vec*)(object+0x44);position.y=0;int i=0;int minimum=0x400000;for(;i<81;i++){if(i%18==17)continue;Pair copy=BattleGrid_GetCellCoordinates(&i);Vec point;__clear(&point,12);point.x=copy.x;point.z=copy.y;int distance=Vector3fix_Distance(&position,&point);if(distance<minimum){best=i;minimum=distance;}}}return best;}
