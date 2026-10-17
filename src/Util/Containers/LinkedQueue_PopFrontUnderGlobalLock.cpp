#include <globaldefs.h>
extern "C" {
struct E{char pad[24];E *next;};struct A{E *head;int pad,count;};void System_PushInterruptFourEnabledStateAndDisable();void Interrupts_UpdateTimerOneFromShiftingGlobalMask();
// Original: arm9/main @ 0x0205E1E4; symbol: func_0205e1e4; size: 0x34.
E *LinkedQueue_PopFrontUnderGlobalLock(A *p){System_PushInterruptFourEnabledStateAndDisable();E *q=p->head;if(q){p->head=q->next;p->count--;}Interrupts_UpdateTimerOneFromShiftingGlobalMask();return q;}
}
