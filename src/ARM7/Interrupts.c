#pragma optimize_for_size off
#pragma dont_inline on

typedef void (*Callback)(int);
typedef struct {
    Callback callback;
    unsigned int stayEnabledAfter;
    int userdata;
} InterruptResponse;

/* Entries 0-3 service DMA completion; entries 4-7 service timer overflow.
 * Startup's WRAM BSS clear initializes every field to zero. */
InterruptResponse ARM7_InterruptResponses[8];
unsigned int ARM7_DisableInterruptMaster(void);
unsigned int ARM7_EnableSpecificInterrupts(unsigned int mask);

void ARM7_SetTimerOverflowCallback(int timer, Callback callback, int userdata) {
    /* Field-base arithmetic preserves the original separate literal addresses. */
    *(Callback *)((unsigned int)&ARM7_InterruptResponses[4].callback + timer * sizeof(InterruptResponse)) = callback;
    *(int *)((unsigned int)&ARM7_InterruptResponses[4].userdata + timer * sizeof(InterruptResponse)) = userdata;
    ARM7_EnableSpecificInterrupts(1 << (timer + 3));
    *(unsigned int *)((unsigned int)&ARM7_InterruptResponses[4].stayEnabledAfter + timer * sizeof(InterruptResponse)) = 1;
}
#define IME (*(volatile unsigned short *)0x04000208)
#define IE (*(volatile unsigned int *)0x04000210)
#define IF (*(volatile unsigned int *)0x04000214)

/* Updates bracket IE/IF writes with IME disabled, retaining the observed
 * volatile read before restoring the previous master-enable state. */
unsigned int ARM7_SetSpecificInterruptsEnabled(unsigned int mask) {
    unsigned int oldIME = ARM7_DisableInterruptMaster();
    unsigned int oldIE = IE;
    IE = mask;
    (void)IME;
    IME = oldIME;
    return oldIE;
}
unsigned int ARM7_DisableInterruptMaster(void) {
    unsigned int old = IME;
    IME = 0;
    return old;
}
unsigned int ARM7_EnableSpecificInterrupts(unsigned int mask) {
    unsigned int oldIME = ARM7_DisableInterruptMaster();
    unsigned int oldIE = IE;
    IE = oldIE | mask;
    (void)IME;
    IME = oldIME;
    return oldIE;
}
unsigned int ARM7_DisableSpecificInterrupts(unsigned int mask) {
    unsigned int oldIME = ARM7_DisableInterruptMaster();
    unsigned int oldIE = IE;
    IE = oldIE & ~mask;
    (void)IME;
    IME = oldIME;
    return oldIE;
}
unsigned int ARM7_AcknowledgeSpecificInterrupts(unsigned int mask) {
    unsigned int oldIME = ARM7_DisableInterruptMaster();
    unsigned int oldIF = IF;
    IF = mask;
    (void)IME;
    IME = oldIME;
    return oldIF;
}
