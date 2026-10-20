#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned GameState_CopyActivePartySlotList(void*,void*);void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);void* memset(void*,int,unsigned);void PartyMenu_RefreshPartyStatusSnapshots(void*);}
// Original: arm9/ov002 @ 0x02154F4C; symbol: GameState_CollectMenuPartyIndicesAndClearRows; size: 0xd8.
extern "C" int PartyMenu_CollectActiveMembersAndRefreshStatus(unsigned char* self){void* game=_ZN9GameState11GetInstanceEv();unsigned char ids[8];unsigned count=GameState_CopyActivePartySlotList(game,ids);unsigned char total=0;ids[count]=4;for(unsigned char i=0;i<count;++i){if(_ZN9GameState21GetPartyMemberByIndexEi(game,ids[i])){(self+total)[0x1c68]=ids[i];++total;}}(self+total)[0x1c68]=4;self[0x1c6d]=total;for(int i=0;i<4;++i)memset(self+0x1a70+i*16,0,4);PartyMenu_RefreshPartyStatusSnapshots(self+0x1a70);return 0;}
