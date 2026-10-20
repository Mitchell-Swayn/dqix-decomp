#pragma once

#include "ProcessorContext.h"
#include "std_library_functions.h"

// Exists at 0x027e0000
struct DTCMData
{
    void (*interruptProcTable[24])();
    BlockedContextList block_60;
    char unknown_60[0x3b80 - 0x68];
    unsigned int irqModeStack[0x100]; // 0x400 bytes of stack space
    char unknown_3f80[0xf8 - 0x80];
    // Bit n is set when interrupt n fires, if it's a DMA / timer interrupt
    unsigned int interruptsFired;
    unsigned int interruptJumpAddress; // holds 0x01ff8000
};

// Original data: arm9/dtcm @ 0x27e0000; symbol: data_027e0000.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c8690c02c8690c02c8690c02946a0c02a46a0c02b46a0c02c46a0c02c8690c02546a0c02646a0c02746a0c02846a0c02c8690c02c8690c02c8690c02c8690c02 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/dtcm.md.
extern DTCMData Entry_UnknownRoleProcedureReferenceRecords;

#define DTCM_DATA (*(DTCMData*)0x027e0000)
#define DTCM_DATA_INTERRUPTS_FIRED (*(unsigned int*)((int)&Entry_UnknownRoleProcedureReferenceRecords + 0x3ff8))

inline BlockedContextList& GetInterruptDataBlockedContextList()
{
    return *(BlockedContextList*)(0x027e0000 + offsetof(DTCMData, block_60));
}