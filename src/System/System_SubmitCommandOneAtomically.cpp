#include <globaldefs.h>
extern "C" unsigned ReadSelectedGlobalValueUnderIRQProtection();
extern "C" int SoundCommand_FlushPendingBatch(unsigned int flags);
extern "C" void SoundCommand_WaitForCompletionTarget(unsigned);
// Original: arm9/main @ 0x020BDC60; symbol: func_020bdc60; size: 0x20.
extern "C" void System_SubmitCommandOneAtomically() { unsigned state=ReadSelectedGlobalValueUnderIRQProtection(); SoundCommand_FlushPendingBatch(1); SoundCommand_WaitForCompletionTarget(state); }
