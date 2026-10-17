#include <globaldefs.h>
#include <GameState/GameState.h>
struct Status {char pad[0x56b];unsigned char value:4;unsigned char rest:4;};struct Object {char pad[0x150];Status* status;};extern "C" void GameState_CollectPresentPartyMemberIndices(signed char*,signed char*);extern "C" Object* GameState_GetObjectWithFlag100(GameState*,int);
// Original: arm9/main @ 0x020DC428; symbol: func_020dc428; size: 0xA8.
extern "C" int CountEligiblePartyEntriesAfterExclusions() {signed char count; signed char party[7];GameState_CollectPresentPartyMemberIndices(party,&count);signed char excluded=0;GameState* state=GameState::GetInstance();for(int i=0;i<count;++i){Object* object=GameState_GetObjectWithFlag100(state,party[i]);if(object){bool active;if(object->status)active=object->status->value!=0;else active=false;if(active)++excluded;}}count-=excluded;return count;}
