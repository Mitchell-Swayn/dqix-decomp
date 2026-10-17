#include "System/Interrupts.h"

// https://problemkaputt.de/gbatek.htm#armcpuflagsconditionfieldcond
// Notably: 
// - 0x80 bit of cpsr set iff IRQ interrupts are disabled
// - 0x40 bit of cpsr set iff FIQ interrupts are disabled

#define BITMASK_IRQ_INTERRUPTS_DISABLED 0x80
#define BITMASK_FIQ_INTERRUPTS_DISABLED 0x40

#define BITMASK_ALL_INTERRUPTS_DISABLED (BITMASK_IRQ_INTERRUPTS_DISABLED | BITMASK_FIQ_INTERRUPTS_DISABLED)

#define BITMASK_PROCESSOR_MODE 0x1f

// Original: arm9/main @ 0x020C96E8; symbol: _Z19EnableIRQInterruptsv; size: 0x14.
int EnableIRQInterrupts()
{
    int oldState;
    __asm("mrs oldState, cpsr");
    int newState = oldState & ~BITMASK_IRQ_INTERRUPTS_DISABLED;
    __asm("msr cpsr_c, newState");
    return oldState & BITMASK_IRQ_INTERRUPTS_DISABLED;
}

// Original: arm9/main @ 0x020C96FC; symbol: _Z20DisableIRQInterruptsv; size: 0x14.
int DisableIRQInterrupts()
{
    int oldState;
    __asm("mrs oldState, cpsr");
    int newState = oldState | BITMASK_IRQ_INTERRUPTS_DISABLED;
    __asm("msr cpsr_c, newState");
    return oldState & BITMASK_IRQ_INTERRUPTS_DISABLED;
}

// Original: arm9/main @ 0x020C9710; symbol: _Z20SetIRQInterruptStatei; size: 0x18.
int SetIRQInterruptState(int to)
{
    int oldState;
    __asm("mrs oldState, cpsr");
    int newState = (oldState & ~BITMASK_IRQ_INTERRUPTS_DISABLED);
    newState |= to;
    __asm("msr cpsr_c, newState");
    return oldState & BITMASK_IRQ_INTERRUPTS_DISABLED;
}

// Original: arm9/main @ 0x020C9728; symbol: _Z26DisableIRQAndFIQInterruptsv; size: 0x14.
int DisableIRQAndFIQInterrupts()
{
    int oldState;
    __asm("mrs oldState, cpsr");
    int newState = oldState | BITMASK_ALL_INTERRUPTS_DISABLED;
    __asm("msr cpsr_c, newState");
    return oldState & BITMASK_ALL_INTERRUPTS_DISABLED;
}

// Original: arm9/main @ 0x020C973C; symbol: _Z26SetIRQAndFIQInterruptStatei; size: 0x18.
int SetIRQAndFIQInterruptState(int to)
{
    int oldState;
    __asm("mrs oldState, cpsr");
    int newState = (oldState & ~BITMASK_ALL_INTERRUPTS_DISABLED);
    newState |= to;
    __asm("msr cpsr_c, newState");
    return oldState & BITMASK_ALL_INTERRUPTS_DISABLED;
}

// Original: arm9/main @ 0x020C9754; symbol: _Z20GetIRQInterruptStatev; size: 0xC.
int GetIRQInterruptState()
{
    int state;
    __asm("mrs state, cpsr");
    return state & BITMASK_IRQ_INTERRUPTS_DISABLED;
}

// Original: arm9/main @ 0x020C9760; symbol: _Z16GetProcessorModev; size: 0xC.
int GetProcessorMode()
{
    int state;
    __asm("mrs state, cpsr");
    return state & BITMASK_PROCESSOR_MODE;
}