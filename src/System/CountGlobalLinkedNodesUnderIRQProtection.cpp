#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Interrupts.h>
extern "C" {
extern void **data_02112780[];
// Original: arm9/main @ 0x020D27A4; symbol: func_020d27a4; size: 0x3C.
unsigned int CountGlobalLinkedNodesUnderIRQProtection(){int state=DisableIRQInterrupts();unsigned int count=0;void **p=data_02112780[2];if(p)do{p=(void **)*p;count++;}while(p);SetIRQInterruptState(state);return count;}
}
