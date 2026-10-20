/* Run the opaque cleanup hook, then repeatedly disable IRQs and halt. */
#pragma dont_inline on
extern void ARM7_TerminationCleanup(void*);
extern int ARM7_DisableIRQInterrupts(void);
extern void ARM7_IdleProcessor(void);
// Original: arm7/wram @ 0x037FE4E8; symbol: ARM7_Terminate.
void ARM7_Terminate(void)
{
 ARM7_TerminationCleanup(0);
 for(;;){ARM7_DisableIRQInterrupts();ARM7_IdleProcessor();}
}
