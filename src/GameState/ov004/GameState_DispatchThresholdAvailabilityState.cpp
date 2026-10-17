#include <globaldefs.h>
ARM
struct State;
extern "C" void *Object_GetGlobalConnectionState();
extern "C" bool TestActiveWordAndGlobalStateNonzero(unsigned int *p);
extern "C" void GameState_ComputeNextThresholdAndPartyContribution(short*,short*,short*,unsigned char*,int*);
extern "C" void func_ov011_021848a0(State* self, unsigned value);
struct Results { unsigned char reached,pad; short next,contribution,current; int tier; };
// Original: arm9/ov004 @ 0x02167D90; symbol: func_ov004_02167d90; size: 0x98.
extern "C" int GameState_DispatchThresholdAvailabilityState(State *self) {
    Results result;
    GameState_ComputeNextThresholdAndPartyContribution(&result.current,&result.contribution,&result.next,&result.reached,&result.tier);
    if (TestActiveWordAndGlobalStateNonzero((unsigned*)Object_GetGlobalConnectionState())) {
        func_ov011_021848a0(self,200);
        return 0;
    }
    if (result.current == 0) func_ov011_021848a0(self,10);
    else if (result.tier < 0) func_ov011_021848a0(self,100);
    else func_ov011_021848a0(self,30);
    return 0;
}
