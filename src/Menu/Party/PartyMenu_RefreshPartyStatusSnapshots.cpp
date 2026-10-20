#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);unsigned GameObject_GetCurrentVocationLevel(void*);}
// Original: arm9/ov002 @0x02154c30; symbol:GameState_RefreshFourPartyAppearanceSnapshots; size:0x110.
// Refreshes four party snapshots when equipment, appearance bytes or record word change.
#pragma always_inline on
inline unsigned short ReadHalf(unsigned char* p,int offset){return U(p,offset);}
inline unsigned ReadWord(unsigned char* p,int offset){return W(p,offset);}
extern "C" int PartyMenu_RefreshPartyStatusSnapshots(unsigned char* self){int changed=0;void* game=_ZN9GameState11GetInstanceEv();unsigned char* member;unsigned char* row;for(int i=0;i<4;++i){member=_ZN9GameState21GetPartyMemberByIndexEi(game,i);if(!member)continue;row=self+i*16;if(U(row,4)==ReadHalf(P(member,0x130),4)&&U(row,6)==ReadHalf(P(member,0x134),0x30)&&U(row,8)==ReadHalf(P(member,0x130),6)&&U(row,10)==ReadHalf(P(member,0x134),0x32)&&row[13]==ReadWord(P(member,0x150),0x950)&&row[12]==GameObject_GetCurrentVocationLevel(member)&&W(row,0)==ReadWord(P(member,0x130),0))continue;U(row,4)=U(P(member,0x130),4);U(row,6)=ReadHalf(P(member,0x134),0x30);U(row,8)=U(P(member,0x130),6);U(row,10)=ReadHalf(P(member,0x134),0x32);row[13]=W(P(member,0x150),0x950);row[12]=GameObject_GetCurrentVocationLevel(member);W(row,0)=W(P(member,0x130),0);changed=1;}return changed;}
