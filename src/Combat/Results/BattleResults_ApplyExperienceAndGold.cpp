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
extern "C" unsigned BattleResults_ComputeParticipationScaledGold(...);
extern "C" unsigned GameState_GetIndexList(...);
extern "C" unsigned GameState_GetObjectWithFlag100(...);
extern "C" unsigned Network_GetConnectionManager(...);
extern "C" unsigned GameObject_GetLinkedIndexedState(...);
extern "C" unsigned PartySelection_GetMemberMask(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
// Original: arm9/ov023 @ 0x021f5150; symbol: GameState_ApplyFourMaskedAmountsAndSaturateCounter; size: 0xd8.
extern "C" int BattleResults_ApplyExperienceAndGold(unsigned self,unsigned mask,unsigned amounts,unsigned output){
unsigned game=_ZN9GameState11GetInstanceEv(),list=GameState_GetIndexList(game);Network_GetConnectionManager();int total=0;for(int i=0;i<4;++i){if(PartySelection_GetMemberMask(mask,(unsigned char)i)){total+=U32(amounts+i*4);unsigned object=GameState_GetObjectWithFlag100(game,i);if(object){object=GameObject_GetLinkedIndexedState(object);if(object){unsigned index=U32(object+0x950);U32(object+0x138+index*4)+=U32(amounts+i*4);}}}}
unsigned value=BattleResults_ComputeParticipationScaledGold(self);U32(output)=value;if(9999999-U32(list+0xf6c)<value)U32(list+0xf6c)=9999999;else U32(list+0xf6c)=U32(list+0xf6c)+value;return total==0&&U32(output)==0;
}