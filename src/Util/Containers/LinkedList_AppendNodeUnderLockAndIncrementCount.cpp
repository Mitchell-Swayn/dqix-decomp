#include <globaldefs.h>
ARM
extern "C" void System_PushInterruptFourEnabledStateAndDisable(void*);extern "C" void Interrupts_UpdateTimerOneFromShiftingGlobalMask();
// Original: arm9/main @ 0x0205E18C; symbol: func_0205e18c; size: 0x58.
extern "C" void LinkedList_AppendNodeUnderLockAndIncrementCount(unsigned char* p,unsigned char* entry){System_PushInterruptFourEnabledStateAndDisable(p);if(*(void**)p){unsigned char* tail=*(unsigned char**)(p+4);*(void**)(tail+24)=entry;*(void**)(p+4)=entry;}else{*(void**)p=entry;*(void**)(p+4)=entry;*(void**)(*(unsigned char**)p+24)=0;}++*(unsigned*)(p+8);*(void**)(*(unsigned char**)(p+4)+24)=0;Interrupts_UpdateTimerOneFromShiftingGlobalMask();}
