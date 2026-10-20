#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" int OverlayLoader_GetPrimarySelectionOrMinusOne();extern "C" void* FieldBattle_GetEncounterRequest(void*);extern "C" void* FieldBattle_GetScene(void*);extern "C" bool GameState_TestProtagonistIndexMatchesStoredByte(signed char*);extern "C" unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);extern "C" void Util_CopyFourSlotRecordSummary(char*,int,signed char*);extern "C" void BattleScene_EnableFlags(unsigned char*,unsigned);extern "C" void Combat_QueueMemberActionSelectionRecord(unsigned short,unsigned short,void*,unsigned char,signed char,int);
// Original: arm9/ov017 @ 0x021CA1A4; symbol: Network_NotifyOtherEnabledSlotsForMatchingParty; size: 0xFC.
extern "C" void Network_NotifyOtherEnabledSlotsForMatchingParty(int index,char* record,int unused,char* resource){if(OverlayLoader_GetPrimarySelectionOrMinusOne()!=0)return;void* nested=P(resource,0x3718);char* party=(char*)FieldBattle_GetEncounterRequest(nested);char* owner=(char*)FieldBattle_GetScene(nested);if(!party||!owner)return;if(U(party,8)!=U(record,4))return;if(GameState_TestProtagonistIndexMatchesStoredByte((signed char*)party)){signed char summary[12];for(int i=0;i<4;i++){if(!PartySelection_GetMemberMask((unsigned char*)party,(unsigned char)i)||index==i)continue;Util_CopyFourSlotRecordSummary(owner,i,summary);Combat_QueueMemberActionSelectionRecord(U(party,8),(unsigned short)i,summary,(unsigned char)W(owner+i*4,0x54f4),(signed char)index,0);}}else BattleScene_EnableFlags((unsigned char*)owner,0x40000000);}
