#include <globaldefs.h>
ARM
extern "C" int SoundCommand_ReclaimCompletedBatch(int);extern "C" void Sound_UpdateJobCompletionAndCombinedVolume();extern "C" void ResourceTimer_UpdateChangedScaledTime();extern "C" void NNSi_SndArcStrmMain();extern "C" void SoundCommand_FlushPendingBatch(int);
// Original: arm9/main @ 0x020BBD9C; symbol: func_020bbd9c; size: 0x30.
extern "C" void Sound_UpdatePlaybackAndFlushCommands(){while(SoundCommand_ReclaimCompletedBatch(0)){}Sound_UpdateJobCompletionAndCombinedVolume();ResourceTimer_UpdateChangedScaledTime();NNSi_SndArcStrmMain();SoundCommand_FlushPendingBatch(0);}
