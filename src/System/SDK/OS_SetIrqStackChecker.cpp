#include <globaldefs.h>
extern "C" { extern unsigned char data_027e0000[]; void SDK_IRQ_STACKSIZE(); }
// SDK C reference: pret/pokeheartgold@14c48938174ec92563afc6d03de5fa162f4cfdce
// lib/NitroSDK/src/os/os_interrupt.c, OS_SetIrqStackChecker, lines 144-147.
// Original: arm9/main @ 0x020C6D48; symbol: func_020c6d48; size: 0x34.
// Writes the SDK canary words below the supervisor stack and at the IRQ stack top.
extern "C" ARM void OS_SetIrqStackChecker()
{
    unsigned int dtcmBase = (unsigned int)data_027e0000;
    *(unsigned int*)(dtcmBase + (0x3f80 - sizeof(unsigned int))) = 0xfddb597d;
    *(unsigned int*)(dtcmBase + 0x3f80 - (unsigned int)SDK_IRQ_STACKSIZE) = 0x7bf9dd5b;
}
