#include <globaldefs.h>
ARM
extern "C" unsigned data_021117ec[]; extern "C" volatile int data_02111808; int GetProcessorMode(); void HandleCommandReceivedFromArm7();
// Original: arm9/main @ 0x020CE148; symbol: func_020ce148; size: 0x40.
 extern "C" void WaitForPendingArm7CommandAndServiceIRQMode() { volatile int* pending=&data_02111808; if(!data_021117ec[7])return; do { if(GetProcessorMode()==18) HandleCommandReceivedFromArm7(); } while(*pending); }
