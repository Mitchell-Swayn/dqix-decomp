/* Drain enabled wireless interrupt sources before publishing the CPU IRQ bit. */
#pragma dont_inline on
extern void ARM7_HandleWirelessSource0080(void);
extern void ARM7_HandleWirelessSource0040(void);
extern void ARM7_HandleWirelessCounterInterrupt(void);
extern void ARM7_HandleWirelessSource4000(void);
extern void ARM7_HandleWirelessSource2000(void);
extern void ARM7_HandleWirelessSource0800(void);
extern void ARM7_HandleWirelessSource0008(void);
extern void ARM7_HandleWirelessSource0004(void);
extern void ARM7_HandleWirelessSource0001(void);
extern void ARM7_HandleWirelessSources0030(void);
extern void ARM7_HandleWirelessSource0002(void);
extern void ARM7_HandleWirelessSource1000(unsigned int);
// Original: arm7/wram @ 0x0380FFF8; interrupt-dispatch pending-bit word.
#define WIRELESS_INTERRUPT_PENDING (*(volatile unsigned int *)0x0380fff8)
// Original: arm7/wram @ 0x037F9310; symbol: func_037f9310; size: 0xd4.
void ARM7_HandleWirelessInterrupt(int unused)
{
    volatile unsigned short *registers = (volatile unsigned short *)0x04808010;
    unsigned int active;
    for (;;) {
        active = registers[0] & registers[1];
        if (!active) break;
        if (active & 0x80) ARM7_HandleWirelessSource0080();
        if (active & 0x40) ARM7_HandleWirelessSource0040();
        if (active & 0x8000) ARM7_HandleWirelessCounterInterrupt();
        if (active & 0x4000) ARM7_HandleWirelessSource4000();
        if (active & 0x2000) ARM7_HandleWirelessSource2000();
        if (active & 0x800) ARM7_HandleWirelessSource0800();
        if (active & 8) ARM7_HandleWirelessSource0008();
        if (active & 4) ARM7_HandleWirelessSource0004();
        if (active & 1) ARM7_HandleWirelessSource0001();
        if (active & 0x30) ARM7_HandleWirelessSources0030();
        if (active & 2) ARM7_HandleWirelessSource0002();
        if (active & 0x1000) ARM7_HandleWirelessSource1000(1);
    }
    WIRELESS_INTERRUPT_PENDING |= 0x01000000;
}
