#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" {void* _ZN9GameState11GetInstanceEv();void* GameState_GetObjectWithFlag100(void*,int);int TestLinkedWordFlagBitSeven(char*);bool TestIndirectComponentFlag100(unsigned char*);unsigned Object_ReadNestedOffset13CByte1COrFF(unsigned char*);int ReadIndirectComponentByte56OrZero(char*);}
inline int IsPartyIndex(int index){int result=0;if(index>=0)result=index<=3;return result;}
// Original: arm9/ov025 @ 0x021E1F40; symbol: func_ov025_021e1f40; size: 0xB4.
extern "C" int TestDifferentIndexAndComponentFlagsClear(unsigned char* p,int index){
if(!ReadIndirectComponentByte56OrZero((char*)p))return 0;
if(index==*(short*)(p+4))return 0;
if(TestLinkedWordFlagBitSeven((char*)p))return 0;
if(Object_ReadNestedOffset13CByte1COrFF(p)==255)return 0;
if(TestIndirectComponentFlag100(p))return 0;
if(IsPartyIndex(*(short*)(p+4))){void* game=_ZN9GameState11GetInstanceEv();char* object=(char*)GameState_GetObjectWithFlag100(game,*(short*)(p+4));if(object&&(*(unsigned*)(object+0x18c)&1))return 0;}
return 1;
}
