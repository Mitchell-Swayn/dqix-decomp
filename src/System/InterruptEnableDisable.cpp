#include "System/Interrupts.h"

#define INTERRUPT_MASTER_ENABLE (*(volatile unsigned short*)0x04000208)
#define INTERRUPT_ENABLE (*(volatile unsigned int*)0x04000210)
#define INTERRUPT_REQUEST_FLAGS (*(volatile unsigned int*)0x04000214)

// Original: arm9/main @ 0x020C6C90; symbol: _Z28SetSpecificInterruptsEnabledj; size: 0x2C.
unsigned int SetSpecificInterruptsEnabled(unsigned int which)
{
    unsigned int oldIME = INTERRUPT_MASTER_ENABLE;
    INTERRUPT_MASTER_ENABLE = 0;

    unsigned int oldIE = INTERRUPT_ENABLE;
    INTERRUPT_ENABLE = which;

    // Why do we need this volatile read?
    (void)INTERRUPT_MASTER_ENABLE;

    INTERRUPT_MASTER_ENABLE = oldIME;
    
    return oldIE;
}

// Original: arm9/main @ 0x020C6CBC; symbol: _Z24EnableSpecificInterruptsj; size: 0x30.
unsigned int EnableSpecificInterrupts(unsigned int mask)
{
    unsigned int oldIME = INTERRUPT_MASTER_ENABLE;
    INTERRUPT_MASTER_ENABLE = 0;

    unsigned int oldIE = INTERRUPT_ENABLE;
    INTERRUPT_ENABLE = oldIE | mask;

    // Why do we need this volatile read?
    (void)INTERRUPT_MASTER_ENABLE;

    INTERRUPT_MASTER_ENABLE = oldIME;
    
    return oldIE;
}

// Original: arm9/main @ 0x020C6CEC; symbol: _Z25DisableSpecificInterruptsj; size: 0x30.
unsigned int DisableSpecificInterrupts(unsigned int mask)
{
    unsigned short oldIME = INTERRUPT_MASTER_ENABLE;
    INTERRUPT_MASTER_ENABLE = 0;

    unsigned int oldIE = INTERRUPT_ENABLE;
    INTERRUPT_ENABLE = oldIE & ~mask;

    // Why do we need this volatile read?
    (void)INTERRUPT_MASTER_ENABLE;

    INTERRUPT_MASTER_ENABLE = oldIME;
    return oldIE;
}

// Original: arm9/main @ 0x020C6D1C; symbol: _Z29AcknowledgeSpecificInterruptsj; size: 0x2C.
unsigned int AcknowledgeSpecificInterrupts(unsigned int flagMask)
{
    unsigned short oldIME = INTERRUPT_MASTER_ENABLE;
    INTERRUPT_MASTER_ENABLE = 0;

    unsigned int oldIF = INTERRUPT_REQUEST_FLAGS;
    INTERRUPT_REQUEST_FLAGS = flagMask;

    // Why do we need this volatile read?
    (void)INTERRUPT_MASTER_ENABLE;

    INTERRUPT_MASTER_ENABLE = oldIME;
    return oldIF;
}