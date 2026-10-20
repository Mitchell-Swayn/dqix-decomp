#pragma optimize_for_size off
#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" int GameState_ReadAttributeBits12To19(GameState*,unsigned);
struct Flags {char pad[0x29c];unsigned type;char pad2a0[12];short count;char pad2ae[0x8f5-0x2ae];unsigned char a;char pad8f6[7];unsigned char b;};
// Original: arm9/main @ 0x02085C08; symbol: func_02085c08; size: 0x78.
extern "C" int GameState_SumTypeDependentFlags48And88(Flags* p) {unsigned type=0x21;if(p->count>0)type=(p->type<<23)>>27;GameState* state=GameState::GetInstance();int result=0;switch(type){case 0x21:if(p->b&1)result+=GameState_ReadAttributeBits12To19(state,0x88);break;case 5:if(p->a&1)result+=GameState_ReadAttributeBits12To19(state,0x48);break;}return result;}
