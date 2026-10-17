#include <globaldefs.h>
struct State{short first;short unused[4];short ready;unsigned pad;unsigned phase;};extern "C" State data_021015a0;extern "C" void Network_HandlePeerJoinLeaveAndStartEvents();extern "C" int DispatchRequestWithModeOne(void(*)());extern "C" void SetGlobalValueExceptModesNineAndTen();
// Original: arm9/main @ 0x0202C958; symbol: func_0202c958; size: 0x54.
extern "C" ARM int PollCallbackStateAndMarkReady(){if(data_021015a0.phase-4<=2)return 1;if(DispatchRequestWithModeOne(Network_HandlePeerJoinLeaveAndStartEvents)!=2){SetGlobalValueExceptModesNineAndTen();return 0;}data_021015a0.first=0;data_021015a0.ready=1;return 1;}
