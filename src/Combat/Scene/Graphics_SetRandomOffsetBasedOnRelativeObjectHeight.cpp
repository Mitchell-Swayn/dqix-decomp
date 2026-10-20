#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov000 @ 0x21832a4; symbol: data_ov000_021832a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 48060000d8120000681f0000f82b00008838000018450000a8510000385e0000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" int GraphicsSetRandomOffsetBasedOnRelativeObjectHeight_UnknownRoleInitializedBytes[];extern "C" void* _ZN9GameState11GetInstanceEv(),*_ZN9GameState20GetGameObjectByIndexEi(void*,int);extern "C" int _ZNK8Object3D9GetHeightEv(void*);extern "C" void BattleCamera_ResetShotAndTransitions(void*,int,int,int),Camera_SetTargetCoordinates(int,unsigned,unsigned,unsigned),Camera_SetOrbitParameters(void*,const void*),BattleCamera_SetTrackedCombatant(void*,int);extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
// Original: arm9/ov000 @ 0x0216d90c; symbol: Graphics_SetRandomOffsetBasedOnRelativeObjectHeight; size 0x128.
extern "C" void Graphics_SetRandomOffsetBasedOnRelativeObjectHeight(char* self,int id){void* game=_ZN9GameState11GetInstanceEv();void* first=_ZN9GameState20GetGameObjectByIndexEi(game,id);if(!first)return;void* second=_ZN9GameState20GetGameObjectByIndexEi(game,B(self,0x263));if(!second)return;int height=_ZNK8Object3D9GetHeightEv(first);int other=_ZNK8Object3D9GetHeightEv(second);int adjust=0;if(other<height&&2.0f<=(float)height)adjust=1;BattleCamera_ResetShotAndTransitions(self,1,1,1);Camera_SetTargetCoordinates((int)self,0,4096,4096);int choice=_Z13NextRandomMaxP6Randomi(P(self,0x21c),8);if(adjust){if(choice==2)choice=7;else if(choice==3)choice=6;else if(choice==4)choice=1;else if(choice==5)choice=0;}int position[3];position[0]=GraphicsSetRandomOffsetBasedOnRelativeObjectHeight_UnknownRoleInitializedBytes[choice];position[1]=0x3000;position[2]=0x8000;Camera_SetOrbitParameters(self,position);BattleCamera_SetTrackedCombatant(self,id);W(self,0x23c)=-20;}
