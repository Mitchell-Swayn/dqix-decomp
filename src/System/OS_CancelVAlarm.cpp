#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" void LinkedList_UnlinkNodeFromGlobalDoublyLinkedList(void*);
// Original: arm9/main @ 0x020C949C; symbol: func_020c949c; size: 0x48.
extern "C" void OS_CancelVAlarm(unsigned* p){int irq=_Z20DisableIRQInterruptsv();p[9]=1;if(!p[0]){_Z20SetIRQInterruptStatei(irq);return;}LinkedList_UnlinkNodeFromGlobalDoublyLinkedList(p);p[0]=0;_Z20SetIRQInterruptStatei(irq);}
