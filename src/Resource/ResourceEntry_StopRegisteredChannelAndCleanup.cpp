#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void SoundCommand_SubmitOpcodeThirteenAndTrackMask(unsigned int, int, unsigned int, int);
extern "C" void LinkedList_RemoveFromGlobalWord2111804ListAtomically(void *);
extern "C" void InvokeGlobalTailListHandler(void *);
extern "C" unsigned int ReadSelectedGlobalValueUnderIRQProtection(void);
extern "C" void SoundCommand_FlushPendingBatch(int);
extern "C" void SoundCommand_WaitForCompletionTarget(unsigned int);
extern "C" void SoundStream_ReleaseAlarmAndUnregister(void *);
// Original: arm9/main @ 0x020BCC7C; symbol: func_020bcc7c; size: 0x74.
extern "C" void ResourceEntry_StopRegisteredChannelAndCleanup(unsigned int *object, unsigned int, unsigned int, unsigned int arg4) {
    int flags = (int)object[9];
    if ((((flags << 30) >> 31) != 0)) {
        unsigned int mask = 1u << object[16];
        SoundCommand_SubmitOpcodeThirteenAndTrackMask(object[17], 0, mask, 0);
        LinkedList_RemoveFromGlobalWord2111804ListAtomically(object + 2);
        InvokeGlobalTailListHandler(object + 5);
        object[9] &= ~2u;
        unsigned int result = ReadSelectedGlobalValueUnderIRQProtection();
        SoundCommand_FlushPendingBatch(1);
        SoundCommand_WaitForCompletionTarget(result);
    }
    SoundStream_ReleaseAlarmAndUnregister(object);
}
