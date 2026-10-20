#pragma dont_inline on

/* IRQ wait-list endpoints are cleared together with the shared VBlank count.
 * Startup also zeroes this eight-byte queue as part of the WRAM BSS interval. */
typedef struct ProcessorContext ProcessorContext;
typedef struct { ProcessorContext *first,*last; } ThreadQueue;
ThreadQueue ARM7_InterruptWaiters;
// Original: arm7/wram @ 0x037FB7CC; symbol: ARM7_InitializeInterruptWaiters.
void ARM7_InitializeInterruptWaiters(void)
{
 ARM7_InterruptWaiters.first=ARM7_InterruptWaiters.last=0;
 *(volatile unsigned int*)0x027ffc3c=0;
}
