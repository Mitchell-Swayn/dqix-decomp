#include <globaldefs.h>
extern "C" void System_PushInterruptFourEnabledStateAndDisable();extern "C" void Interrupts_UpdateTimerOneFromShiftingGlobalMask();extern "C" void CopyStructuredRecordFields(void*,const void*);
// Original: arm9/main @ 0x0202C478; symbol: func_0202c478; size: 0x90.
extern "C" ARM void Network_ExpirePeerTimersAndCompactEntries(char* p){System_PushInterruptFourEnabledStateAndDisable();for(int i=0;i<*(int*)(p+12);++i){*((int*)(p+0x790)+i)-=16;if(*(int*)(p+i*4+0x790)<=0){for(int j=i;j<*(int*)(p+12)-1;++j)CopyStructuredRecordFields(p+16+j*0xc0,p+16+(j+1)*0xc0);--*(int*)(p+12);}}Interrupts_UpdateTimerOneFromShiftingGlobalMask();}
