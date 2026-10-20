#include <globaldefs.h>
ARM
struct State;
extern "C" void *Network_GetConnectionManager();
extern "C" bool Network_IsClientSession(unsigned int *p);
extern "C" void GameState_ComputeNextThresholdAndPartyContribution(short*,short*,short*,unsigned char*,int*);
extern "C" void Menu_QueueScriptEntry(State* self, unsigned value);
struct Results { unsigned char reached,pad; short next,contribution,current; int tier; };
// Original: arm9/ov004 @ 0x02167D90; symbol: func_ov004_02167d90; size: 0x98.
extern "C" int GameState_DispatchThresholdAvailabilityState(State *self) {
    Results result;
    GameState_ComputeNextThresholdAndPartyContribution(&result.current,&result.contribution,&result.next,&result.reached,&result.tier);
    if (Network_IsClientSession((unsigned*)Network_GetConnectionManager())) {
        Menu_QueueScriptEntry(self,200);
        return 0;
    }
    if (result.current == 0) Menu_QueueScriptEntry(self,10);
    else if (result.tier < 0) Menu_QueueScriptEntry(self,100);
    else Menu_QueueScriptEntry(self,30);
    return 0;
}
