#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct HighTwoBits{unsigned char low:6,high:2;};
extern "C" unsigned GameState_SetSelectedStateWordFields(...);
extern "C" unsigned Network_DispatchSharedWirelessStateOperation(...);
extern "C" unsigned Network_RequestSharedStateSeven(...);
extern "C" unsigned Network_GetWirelessLifecycleState(...);
extern "C" unsigned Network_GetConnectionWorkspace(...);
extern "C" unsigned Network_RequestDcfDisconnect(...);
extern "C" unsigned Network_StartAccessPointSearchPhase(...);
// Original: arm9/ov031 @ 0x02214928; symbol: DispatchSharedStateAndChooseNextStatus.
extern "C" unsigned Network_ProcessConnectionRecovery(){unsigned char* state=(unsigned char*)Network_GetConnectionWorkspace(16);unsigned result=9;switch(Network_GetWirelessLifecycleState()){case 3:{unsigned mode=((HighTwoBits*)(state+0xd0c))->high;result=B(state,0xd0e);if(mode==1){B(state+B(state,0xd13)*4,0x444)=0;result=7;}else if(result>=3&&result<=5)Network_StartAccessPointSearchPhase(result);break;}case 6:Network_RequestSharedStateSeven();break;case 9:Network_RequestDcfDisconnect();break;case 12:Network_DispatchSharedWirelessStateOperation();GameState_SetSelectedStateWordFields(4);result=17;break;case 11:GameState_SetSelectedStateWordFields(0);result=17;break;default:break;}return result;}
