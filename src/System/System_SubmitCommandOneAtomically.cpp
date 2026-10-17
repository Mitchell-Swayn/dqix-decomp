#include <globaldefs.h>
extern "C" unsigned ReadSelectedGlobalValueUnderIRQProtection();
extern "C" void func_020d24c4(unsigned);
extern "C" void SoundCommand_WaitUntilRecordCompletes(unsigned);
// Original: arm9/main @ 0x020BDC60; symbol: func_020bdc60; size: 0x20.
extern "C" void System_SubmitCommandOneAtomically() { unsigned state=ReadSelectedGlobalValueUnderIRQProtection(); func_020d24c4(1); SoundCommand_WaitUntilRecordCompletes(state); }
