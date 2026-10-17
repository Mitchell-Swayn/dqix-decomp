/* Reset microphone IPC slots and operation state, then stop timer3. */
#pragma dont_inline on
typedef struct {unsigned short commands[16];int operation;} MicrophoneState;
extern MicrophoneState ARM7_MicrophoneState;
extern unsigned short ARM7_MicrophoneCommands[16];
// Original: arm7/wram @ 0x03806610; symbol: ARM7_InitializeMicrophoneState.
void ARM7_InitializeMicrophoneState(void)
{
 int slot;
 ARM7_MicrophoneState.operation=0;
 slot=0;
 do {ARM7_MicrophoneCommands[slot]=0;slot++;} while(slot<16);
 *(volatile unsigned short*)0x0400010e &= ~0x80;
}
