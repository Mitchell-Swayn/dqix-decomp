#pragma dont_inline on
extern void ARM7_BusLockWait(int);
extern int ARM7_SendIpcCommand(int,unsigned int,int);
/* Retry cartridge-channel IPC sends, yielding a one-cycle bus wait on failure. */
// Original: arm7/wram @ 0x038075F8; symbol: ARM7_SendCartridgeIpcCommand.
void ARM7_SendCartridgeIpcCommand(unsigned int command)
{
 while(ARM7_SendIpcCommand(13,command,0)!=0)ARM7_BusLockWait(1);
}
