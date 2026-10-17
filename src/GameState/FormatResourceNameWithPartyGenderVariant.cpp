#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" void PopulateMemberDisplayFromResolvedDescriptor();extern "C" int ReadIndirectByteOrMinusOne(void*);extern "C" char* GameState_GetObjectWithFlag100(GameState*,int);extern "C" char data_020f0cff[];
struct Flags {unsigned char enabled:1,rest:7;};
// Original: arm9/main @ 0x02072D58; symbol: func_02072d58; size: 0xDC.
extern "C" void FormatResourceNameWithPartyGenderVariant(int id,char* first,char* second){
 PopulateMemberDisplayFromResolvedDescriptor();char* state=(char*)GameResources_GetInstance();unsigned char gender=0;
 if(ReadIndirectByteOrMinusOne(*(void**)(state+0x36fc))==10){char* member=(char*)GameState::GetInstance()->GetCombatantByIndex(id);if(member)gender=(*(char**)(member+0x138))[0x26];}
 if(gender){sprintf(second,data_020f0cff,first,'b');sprintf(first,data_020f0cff,first,'f');}else{sprintf(first,data_020f0cff,first,'n');sprintf(second,data_020f0cff,first,'e');}
 char* member=GameState_GetObjectWithFlag100(GameState::GetInstance(),id);if(!member)return;if(((Flags*)(*(char**)(member+0x150)+0x49c))->enabled==1)*first='w';
}
