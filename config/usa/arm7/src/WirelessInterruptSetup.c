/* Attach the wireless interrupt callback and enable its CPU interrupt source. */
#pragma dont_inline on
extern void ARM7_SetInterruptHandler(unsigned int, void (*)(int));
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern void ARM7_HandleWirelessInterrupt(int);
// Original: arm7/mainram @ 0x027EBBD4; symbol: func_027ebbd4; size: 0x24.
void ARM7_EnableWirelessInterrupt(void)
{
    ARM7_SetInterruptHandler(0x01000000, ARM7_HandleWirelessInterrupt);
    ARM7_EnableSpecificInterrupts(0x01000000);
}
// Original: arm7/mainram @ 0x027EBBF8; symbol: func_027ebbf8; size: 0x20.
void ARM7_DisableWirelessInterrupt(void)
{
    ARM7_DisableSpecificInterrupts(0x01000000);
    ARM7_SetInterruptHandler(0x01000000, 0);
}
