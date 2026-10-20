#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Nibble{unsigned char lower:4,upper:4;};
extern "C" unsigned Network_AdvanceBroadChannelSearch(...);
extern "C" unsigned Network_GetConnectionPhase(...);
extern "C" unsigned Network_GetWirelessLifecycleState(...);
extern "C" unsigned Network_SelectPendingAccessPointAndStopScan(...);
extern "C" unsigned Network_GetConnectionWorkspace(...);
extern "C" unsigned System_RefreshTimestampAndNotifyWithMode200000(...);
extern "C" unsigned Network_AdvanceCandidateAccessPointSearch(...);
extern "C" unsigned Network_AdvanceTimedSsidChannelScan(...);
// Original: arm9/ov031:02214a04
extern "C" int Network_ProcessAccessPointSearchPhase(){char* p=(char*)Network_GetConnectionWorkspace(16);int state=Network_GetConnectionPhase();int mode=Network_GetWirelessLifecycleState();if(state==2&&mode==3)state=System_RefreshTimestampAndNotifyWithMode200000(p);else if(state==6)state=Network_SelectPendingAccessPointAndStopScan(p,state);else if(mode==3||mode==6){state=Network_SelectPendingAccessPointAndStopScan(p,state);if(state!=7){if(state==3)state=Network_AdvanceBroadChannelSearch(p);else if(state==4)state=Network_AdvanceCandidateAccessPointSearch(p);else if(state==5)state=Network_AdvanceTimedSsidChannelScan(p);}}return state;}
