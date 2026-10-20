#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" void PartyAppearance_FormatMemberResourceStem();extern "C" int LinkedQueue_GetFrontKindOrInvalid(void*);extern "C" char* GameState_GetObjectWithFlag100(GameState*,int);extern "C" char FormatResourceNameWithPartyGenderVariant_FormatSC[];
struct Flags {unsigned char enabled:1,rest:7;};
// Original: arm9/main @ 0x02072D58; symbol: func_02072d58; size: 0xDC.
extern "C" void FormatResourceNameWithPartyGenderVariant(int id,char* first,char* second){
 PartyAppearance_FormatMemberResourceStem();char* state=(char*)GameResources_GetInstance();unsigned char gender=0;
 if(LinkedQueue_GetFrontKindOrInvalid(*(void**)(state+0x36fc))==10){char* member=(char*)GameState::GetInstance()->GetCombatantByIndex(id);if(member)gender=(*(char**)(member+0x138))[0x26];}
 if(gender){sprintf(second,FormatResourceNameWithPartyGenderVariant_FormatSC,first,'b');sprintf(first,FormatResourceNameWithPartyGenderVariant_FormatSC,first,'f');}else{sprintf(first,FormatResourceNameWithPartyGenderVariant_FormatSC,first,'n');sprintf(second,FormatResourceNameWithPartyGenderVariant_FormatSC,first,'e');}
 char* member=GameState_GetObjectWithFlag100(GameState::GetInstance(),id);if(!member)return;if(((Flags*)(*(char**)(member+0x150)+0x49c))->enabled==1)*first='w';
}
