#pragma dont_inline on

/* Timer 0 runs with a /64 prescaler. The overflow counter extends the hardware
 * 16-bit counter; the timestamp reader compensates for a pending overflow IRQ.
 * This unit uses memory-mapped registers and ordinary C, with CPSR operations
 * supplied by the separately reviewed CPU-status unit. */
typedef unsigned long long uint64_t;
typedef struct {
    unsigned short flags;
    unsigned short reserved; /* Alignment storage; no semantic use established. */
} TimerInitFlags;
typedef struct {
    unsigned short isInitialized;
    int reloadTimerOnNextInterrupt;
    volatile uint64_t numTimerOverflows;
} Timer64Bit;

/* This compiler emits these BSS definitions in reverse declaration order. */
Timer64Bit ARM7_TimerState;
TimerInitFlags ARM7_TimerInitFlags;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_SetInterruptHandler(unsigned int, void (*)(int));
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
extern void ARM7_SetTimerOverflowCallback(int, void (*)(int), int);
void ARM7_On16BitTimerOverflow(int);
#define TIMER_N_COUNTER(n) (*(volatile unsigned short*)(0x04000100 + 4 * (n)))
#define TIMER_N_CONTROL(n) (*(volatile unsigned short*)(0x04000102 + 4 * (n)))
#define TIMER_CONTROL_FLAGS_START 0x80
#define TIMER_CONTROL_FLAGS_ENABLE_IRQ_ON_OVERFLOW 0x40
#define TIMER_CONTROL_FLAGS_PRESCALE_64X 1
#define IRQ_MASK_TIMER_0_OVERFLOW 8
#define INTERRUPT_REQUEST_FLAGS (*(volatile unsigned int*)0x04000214)

void ARM7_MarkAlarmInitializationFlagBit(int bit)
{
    ARM7_TimerInitFlags.flags |= (1 << bit);
}

void ARM7_Initialize64BitTimer(void)
{
    if (ARM7_TimerState.isInitialized)
        return;

    ARM7_TimerState.isInitialized = 1;
    ARM7_MarkAlarmInitializationFlagBit(0);
    ARM7_TimerState.numTimerOverflows = 0;
    TIMER_N_CONTROL(0) = 0;
    TIMER_N_COUNTER(0) = 0;
    TIMER_N_CONTROL(0) = TIMER_CONTROL_FLAGS_START | TIMER_CONTROL_FLAGS_ENABLE_IRQ_ON_OVERFLOW | TIMER_CONTROL_FLAGS_PRESCALE_64X;

    ARM7_SetInterruptHandler(IRQ_MASK_TIMER_0_OVERFLOW, &ARM7_On16BitTimerOverflow);
    ARM7_EnableSpecificInterrupts(IRQ_MASK_TIMER_0_OVERFLOW);
    ARM7_TimerState.reloadTimerOnNextInterrupt = 0;
}

int ARM7_Is64BitTimerInitialized(void)
{
    return ARM7_TimerState.isInitialized;
}

void ARM7_On16BitTimerOverflow(int unused)
{
    ARM7_TimerState.numTimerOverflows++;
    if (ARM7_TimerState.reloadTimerOnNextInterrupt)
    {
        TIMER_N_CONTROL(0) = 0;
        TIMER_N_COUNTER(0) = 0;
        TIMER_N_CONTROL(0) = TIMER_CONTROL_FLAGS_START | TIMER_CONTROL_FLAGS_ENABLE_IRQ_ON_OVERFLOW | TIMER_CONTROL_FLAGS_PRESCALE_64X;
        
        ARM7_TimerState.reloadTimerOnNextInterrupt = 0;
    }
    ARM7_SetTimerOverflowCallback(0, &ARM7_On16BitTimerOverflow, 0);
}

uint64_t ARM7_GetCurrentTimestamp(void)
{
    int priorState = ARM7_DisableIRQInterrupts();
    volatile unsigned short lowBits = TIMER_N_COUNTER(0);

    volatile uint64_t highBits = ARM7_TimerState.numTimerOverflows & 0xffffffffffff;
    if ((INTERRUPT_REQUEST_FLAGS & IRQ_MASK_TIMER_0_OVERFLOW) && !(lowBits & 0x8000))
        highBits++;

    ARM7_SetIRQInterruptState(priorState);
    return (highBits << 16) | lowBits;
}

