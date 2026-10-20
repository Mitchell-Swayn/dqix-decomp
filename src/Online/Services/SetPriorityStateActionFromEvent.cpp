#include <globaldefs.h>
ARM
extern "C" char* Network_GetConnectionWorkspace(unsigned);extern "C" void WirelessScan_ProcessAccessPoint(unsigned);
// Original: arm9/ov031 @ 0x02213C10; symbol: SetPriorityStateActionFromEvent; size: 0x8C.
// Maps active event5 identifiers13/15/17 to action bytes1/2/3, or dispatches event7.
extern "C" void SetPriorityStateActionFromEvent(char* event) {
char* state=Network_GetConnectionWorkspace(0x10);
if(*(short*)event==5){if(!*(short*)(event+2))return;switch(*(unsigned*)(event+8)){case 13:state[0xd14]=1;break;case 15:state[0xd14]=2;break;case 17:state[0xd14]=3;break;default:state[0xd14]=4;break;}}
else if(*(short*)event==7)WirelessScan_ProcessAccessPoint(*(unsigned*)(event+4));
}