#include <globaldefs.h>
// Original data: arm9/dtcm @ 0x27e0000; symbol: data_027e0000.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c8690c02c8690c02c8690c02946a0c02a46a0c02b46a0c02c46a0c02c8690c02546a0c02646a0c02746a0c02846a0c02c8690c02c8690c02c8690c02c8690c02 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/dtcm.md.
extern "C" { extern unsigned char Entry_UnknownRoleProcedureReferenceRecords[]; void SDK_IRQ_STACKSIZE(); }
// SDK C reference: pret/pokeheartgold@14c48938174ec92563afc6d03de5fa162f4cfdce
// lib/NitroSDK/src/os/os_interrupt.c, OS_SetIrqStackChecker, lines 144-147.
// Original: arm9/main @ 0x020C6D48; symbol: func_020c6d48; size: 0x34.
// Writes the SDK canary words below the supervisor stack and at the IRQ stack top.
extern "C" ARM void OS_SetIrqStackChecker()
{
    unsigned int dtcmBase = (unsigned int)Entry_UnknownRoleProcedureReferenceRecords;
    *(unsigned int*)(dtcmBase + (0x3f80 - sizeof(unsigned int))) = 0xfddb597d;
    *(unsigned int*)(dtcmBase + 0x3f80 - (unsigned int)SDK_IRQ_STACKSIZE) = 0x7bf9dd5b;
}
