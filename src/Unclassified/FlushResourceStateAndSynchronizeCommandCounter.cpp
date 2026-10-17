#include <globaldefs.h>
ARM
extern "C" void DispatchSavedStateAndSynchronizeCommandCounter();extern "C" void ProcessEightMaskBitsAndDispatchCommandThirteen(unsigned,unsigned,unsigned,unsigned);extern "C" unsigned ReadSelectedGlobalValueUnderIRQProtection();extern "C" void func_020d24c4(unsigned);extern "C" void SoundCommand_WaitUntilRecordCompletes(unsigned);
// Original: arm9/main @ 0x020BBDD8; symbol: func_020bbdd8; size: 0x38.
extern "C" void FlushResourceStateAndSynchronizeCommandCounter(){DispatchSavedStateAndSynchronizeCommandCounter();ProcessEightMaskBitsAndDispatchCommandThirteen(0,0,0,0);unsigned state=ReadSelectedGlobalValueUnderIRQProtection();func_020d24c4(1);SoundCommand_WaitUntilRecordCompletes(state);}
