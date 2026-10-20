#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void Tavern_GetRosterCapacityAndFreeStoredSlots(void*,short*,short*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetIndexList(void*);
extern "C" void Tavern_PopulateStoredCharacterRecruitmentList(void*);
// Original: arm9/ov003 @ 0x02165BD8; symbol: UpdateWrappedFourEntrySelectionPage; size: 0xc4.
extern "C" void Tavern_UpdateRecruitmentListPage(char* self) {
 short a,b;Tavern_GetRosterCapacityAndFreeStoredSlots(self,&a,&b);b-=B(GameState_GetIndexList(_ZN9GameState11GetInstanceEv()),0xf7c)-1;int count=B(GameState_GetIndexList(_ZN9GameState11GetInstanceEv()),0x2c8c);if(b)count++;int pages=(count+3)/4;
 if(W(self,0x45c)&16)S(self,0x49f)++;else if(W(self,0x45c)&32)S(self,0x49f)--;
 if(pages<=S(self,0x49f))B(self,0x49f)=0;else if(S(self,0x49f)<0)B(self,0x49f)=pages-1;Tavern_PopulateStoredCharacterRecruitmentList(self);
}
