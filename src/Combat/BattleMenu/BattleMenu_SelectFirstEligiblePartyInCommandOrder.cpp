#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned BattleMenu_FindPartyCommandRecord(...);
extern "C" unsigned GameState_GetIndexList(...);
extern "C" unsigned GameObject_GetLinkedIndexedState(...);
extern "C" unsigned BattleMenu_HasCommandBlockingStatus(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState21GetPartyMemberByIndexEi(...);
// Original: arm9/ov000 @ 0x0217f990; symbol: SelectEligibleIndexedFourSlotRecord.
extern "C" int BattleMenu_SelectFirstEligiblePartyInCommandOrder(char* p){void* game=(void*)_ZN9GameState11GetInstanceEv();char* list=(char*)GameState_GetIndexList(game);unsigned char count=B(list,0xf7c);int found=0;for(unsigned char i=0;i<count;i++){int index=S(p+i,0x70);char* record=(char*)BattleMenu_FindPartyCommandRecord(p,index);if(!record)continue;if((int)U(record,0x4c)<0)continue;if(!B(record,0x87)||S(record+S(record,0x18),0x10)==100)continue;if(BattleMenu_HasCommandBlockingStatus(record))continue;if(!B(record,0x445))continue;char* member=(char*)_ZN9GameState21GetPartyMemberByIndexEi(game,index);if(member){char* data=(char*)GameObject_GetLinkedIndexedState(member);if((signed char)U(data,0x94c)!=5)continue;}U(p,0x17c)=index;found=1;break;}return found;}
