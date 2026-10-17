#include <globaldefs.h>
#include <System/Matrix.h>
ARM
#pragma opt_common_subs off
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
struct RestoreState {unsigned char pad[0x174];unsigned char pending,done;
 bool Test(unsigned char mask){return (pending&mask)!=0;}
};
// Original: arm9/ov017 @ 0x021BD440; symbol: func_ov017_021bd440; size: 0x90.
extern "C" void GameState_RestoreMaskedPartyMemberTransform(RestoreState* state,int index){
 unsigned char* p=(unsigned char*)state;
 int restore;
 unsigned char mask=1<<index;
 restore=0;
 if(state->Test(mask))restore=1;
 p[0x174]&=~mask;
 p[0x175]|=mask;
 if(!restore)return;
 unsigned char* obj=_ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(),index);
 if(!obj)return;
 *(Vector3fix*)(obj+0x44)=((Vector3fix*)(p+0x188))[index];
 int angle=*(int*)(p+0x1b8+index*4);
 *(int*)(obj+0x50)=0;
 *(int*)(obj+0x54)=angle;
 *(int*)(obj+0x58)=0;
}
