#include <globaldefs.h>
ARM
extern "C" int Network_ProcessWirelessShutdown();
extern "C" int System_IsSharedSequenceReady();
extern "C" void WfcNetCheck_DestroySession();
extern "C" void Ov031_FinalizePendingContextTransition();
// Original: arm9/ov031 @ 0x022141D4; symbol: AdvanceSharedSequenceStateByte; size: 0x88.
// Advances one-byte shared sequence state, reports terminal success/failure from polling helper.
extern "C" int Network_AdvanceConnectionShutdown(unsigned char* p){
 if(*p<=10){int result=Network_ProcessWirelessShutdown();if(result==1){*p=0;return 1;}if(result==-1){*p=18;return 1;}}
 else if(*p==14){Ov031_FinalizePendingContextTransition();WfcNetCheck_DestroySession();*p=12;}
 else if(*p<18){if(System_IsSharedSequenceReady()==1)*p=10;}
 return 0;
}
