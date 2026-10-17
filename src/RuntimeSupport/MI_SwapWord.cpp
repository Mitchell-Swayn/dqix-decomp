// SDK support (community reconstruction): MI_SwapWord.
// SDK support (community reconstruction): NitroSDK MI_SwapWord.
// Original: arm9/main @ 0x020CA7E0; symbol: func_020ca7e0; size: 0x8.
// Reference: pret/pokediamond@b623abef1b4dfe204ca50aab42447ac00c134290 arm9/lib/NitroSDK/src/MI_swap.c
// Atomically exchange the input word with memory and return the old memory word.
#pragma thumb off
extern "C" asm unsigned int MI_SwapWord(register unsigned int setData,
    register volatile unsigned int* destp)
{
    swp setData, setData, [destp]
    bx lr
}
