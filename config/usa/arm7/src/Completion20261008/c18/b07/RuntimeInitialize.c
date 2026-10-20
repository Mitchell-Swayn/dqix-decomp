/* Initialize ARM7 runtime services in their cartridge boot order. Thread and
 * communication initialization remain explicit external dependencies. */
#pragma dont_inline on
extern void ARM7_InitializeArenas(void);
extern void ARM7_StartIPC(void);
extern void ARM7_InitializeBusLocks(void);
extern void ARM7_InitializeInterruptWaiters(void);
extern void ARM7_Initialize64BitTimer(void);
extern void ARM7_InitializeActiveAlarmList(void);
extern void ARM7_InitializeThreads(void);
extern void ARM7_InitializeReset(void);
extern void ARM7_InitializeCommunicationServices(void);
// Original: arm7/wram @ 0x037FCE1C; symbol: ARM7_InitializeRuntimeServices.
void ARM7_InitializeRuntimeServices(void)
{
 ARM7_InitializeArenas();
 ARM7_StartIPC();
 ARM7_InitializeBusLocks();
 ARM7_InitializeInterruptWaiters();
 ARM7_Initialize64BitTimer();
 ARM7_InitializeActiveAlarmList();
 ARM7_InitializeThreads();
 ARM7_InitializeReset();
 ARM7_InitializeCommunicationServices();
}
