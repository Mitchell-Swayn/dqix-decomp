/* Wait briefly for a hardware counter to advance, then resume source 0x1000. */
#pragma dont_inline on
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
extern void ARM7_HandleWirelessSource1000(unsigned int);
// Original: arm7/wram @ 0x037FA694; symbol: func_037fa694; size: 0x68.
void ARM7_OnWirelessDelay(void *unused)
{
    unsigned int interrupts = ARM7_DisableSpecificInterrupts(0x01000000);
    volatile unsigned short *registers = (volatile unsigned short *)0x04808210;
    unsigned short before = *registers;
    int count = 100;
    registers[0x34 / 2] = 0x1000;
    while (count) {
        if (before != *registers) break;
        count--;
    }
    *(volatile unsigned short *)0x04808244 = 0;
    ARM7_HandleWirelessSource1000(0);
    ARM7_EnableSpecificInterrupts(interrupts);
}
