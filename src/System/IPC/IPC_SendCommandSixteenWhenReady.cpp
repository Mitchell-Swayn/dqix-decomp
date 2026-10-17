#include <globaldefs.h>
extern "C" int PowerManagement_IsLcdPowerEnabled();
extern "C" unsigned PowerManagement_ExecuteCommandSynchronously(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020CE7E0; symbol: func_020ce7e0; size: 0x30.
extern "C" unsigned IPC_SendCommandSixteenWhenReady(unsigned value) { if (!PowerManagement_IsLcdPowerEnabled()) return 0; return PowerManagement_ExecuteCommandSynchronously(0x10,(unsigned short)value,0); }
