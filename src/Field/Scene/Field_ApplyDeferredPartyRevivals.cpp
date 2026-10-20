#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned char* _ZN9GameState20GetUnknownGameObjectEv(void*);int _ZNK8Object3D7GetFlagEi(void*,int);unsigned char* GameState_ReadUnkF8(void*);void* GameState_GetObjectWithFlag100(void*,int);void GameObject_ApplyLimitAndClearTransitionFlag(void*,int,int);void Network_QueueCurrentPartyMemberState(int,int,int,int);}
// Original: arm9/ov017 @ 0x02191BDC; symbol: GameState_ApplyDeferredFourMemberLimits; size: 0xe4.
extern "C" void Field_ApplyDeferredPartyRevivals(unsigned char* self,int force){void* game=_ZN9GameState11GetInstanceEv();unsigned char* leader=_ZN9GameState20GetUnknownGameObjectEv(game);if(!leader||H(leader,0xac)!=0||_ZNK8Object3D7GetFlagEi(leader,0x8000000))return;if(!force){unsigned char* tint=GameState_ReadUnkF8(game);if(P(self,0x370c)[2]||tint[2])return;}unsigned char* entry=self+0x449c;for(int i=0;i<4;++i){if(entry[0]){void* object=GameState_GetObjectWithFlag100(game,i);if(object){GameObject_ApplyLimitAndClearTransitionFlag(object,H(entry,2),1);Network_QueueCurrentPartyMemberState(i,1,0,1);}entry[0]=0;H(entry,2)=0;}entry+=4;}}
