#include <globaldefs.h>
ARM
extern "C" void NNSi_SndCaptureBeginSleep();extern "C" void SoundCommand_SubmitOpcodeThirteenAndTrackMask(unsigned,unsigned,unsigned,unsigned);extern "C" unsigned ReadSelectedGlobalValueUnderIRQProtection();extern "C" int SoundCommand_FlushPendingBatch(unsigned int flags);extern "C" void SoundCommand_WaitForCompletionTarget(unsigned);
// Original: arm9/main @ 0x020BBDD8; symbol: func_020bbdd8; size: 0x38.
extern "C" void Sound_StopPlaybackAndWaitForCommands(){NNSi_SndCaptureBeginSleep();SoundCommand_SubmitOpcodeThirteenAndTrackMask(0,0,0,0);unsigned state=ReadSelectedGlobalValueUnderIRQProtection();SoundCommand_FlushPendingBatch(1);SoundCommand_WaitForCompletionTarget(state);}
