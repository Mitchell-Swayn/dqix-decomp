#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20feffc; symbol: data_020feffc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4168 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int Network_GetConnectionState();extern "C" void Network_RequestPeerDiscoveryStop();extern "C" void _Z19SleepCurrentContextj(unsigned);extern "C" void Network_ConfigureStateFromMode(int,void*);extern "C" char NetworkConnectToDiscoveredPeerByIndex_UnknownRoleZeroInitializedStorage[];extern "C" char* _ZN9GameState11GetInstanceEv();extern "C" unsigned long long _Z19GetCurrentTimestampv();
// Original: arm9/main @ 0x0202B840; symbol: func_0202b840; size: 0xC0.
extern "C" int Network_ConnectToDiscoveredPeerByIndex(unsigned* p,int id){if(id<0)return 1;int n=0;while(Network_GetConnectionState()==2){Network_RequestPeerDiscoveryStop();if(++n>5000)return 0;_Z19SleepCurrentContextj(1);}n=0;while(Network_GetConnectionState()!=1){if(++n>5000)return 0;_Z19SleepCurrentContextj(1);}Network_ConfigureStateFromMode(5,NetworkConnectToDiscoveredPeerByIndex_UnknownRoleZeroInitializedStorage+id*192);*p=6;char* state=_ZN9GameState11GetInstanceEv();*(unsigned long long*)(state+1008)=_Z19GetCurrentTimestampv();return 1;}
