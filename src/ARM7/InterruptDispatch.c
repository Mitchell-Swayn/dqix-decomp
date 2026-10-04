#pragma dont_inline on

/* Clear the registered callback before invoking it, record the fired IRQ,
 * then disable the IRQ unless its response requests continued delivery. */
typedef void (*Callback)(int);
typedef struct { Callback callback; unsigned int stayEnabledAfter; int userdata; } InterruptResponse;
extern InterruptResponse ARM7_InterruptResponses[8];
extern const unsigned short ARM7_InterruptResponseIDs[8];
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
#define FIRED (*(volatile unsigned int*)0x0380fff8)
void ARM7_DispatchInterruptResponse(int index)
{
 unsigned int mask=1<<ARM7_InterruptResponseIDs[index];
 Callback callback=*(Callback*)((unsigned int)&ARM7_InterruptResponses[0].callback+index*sizeof(InterruptResponse));
 *(Callback*)((unsigned int)&ARM7_InterruptResponses[0].callback+index*sizeof(InterruptResponse))=0;
 if(callback) callback(*(int*)((unsigned int)&ARM7_InterruptResponses[0].userdata+index*sizeof(InterruptResponse)));
 FIRED|=mask;
 if(!*(unsigned int*)((unsigned int)&ARM7_InterruptResponses[0].stayEnabledAfter+index*sizeof(InterruptResponse))) ARM7_DisableSpecificInterrupts(mask);
}
