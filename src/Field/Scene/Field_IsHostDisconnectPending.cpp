#include <globaldefs.h>
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsClientSession(void*);
extern "C" int Network_TestMemberDisconnectFlag(void*,int);
// Original: arm9/ov017 @ 0x021959B4; symbol: func_ov017_021959b4; size: 0x38.
extern "C" ARM int Field_IsHostDisconnectPending() { void* context=Network_GetConnectionManager(); if(Network_IsClientSession(context)) { if(Network_TestMemberDisconnectFlag(context,0)) return 1; } return 0; }
