/* Merge status flags under the wireless IRQ mask and schedule dispatch slot 21. */
#pragma dont_inline on
typedef struct { unsigned char unknown000[0x3f4]; unsigned short flags; } WirelessStatusFlagsView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessStatusFlagsState (*(WirelessStatusFlagsView **)0x0380fff4)
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
extern void ARM7_EnqueueWirelessDispatchSlot(int, int);
// Original: arm7/mainram @ 0x027EB384; symbol: func_027eb384; size: 0x44.
void ARM7_QueueWirelessStatusFlags(unsigned int flags)
{
    unsigned int interrupts = ARM7_DisableSpecificInterrupts(0x01000000);
    ARM7_WirelessStatusFlagsState->flags |= flags;
    ARM7_EnableSpecificInterrupts(interrupts);
    ARM7_EnqueueWirelessDispatchSlot(2, 21);
}
