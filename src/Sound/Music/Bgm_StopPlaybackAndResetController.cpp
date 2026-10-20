#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" void ResourceHandle_ReplaceValueAndInvalidateFileIndices(int, int, int);
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(int, int);
extern "C" void Sound_UpdatePlaybackAndFlushCommands(void);
extern "C" void ResourceHandle_RestoreSavedArchiveHeapState(int);
extern "C" void ResourceHandle_InitializeSequenceHandle(int);
extern "C" void Bgm_SetPlaybackVolumeAndFade(int, int, int);

// Original: arm9/main @ 0x0209C20C; symbol: func_0209c20c; size: 0x6C.
extern "C" void Bgm_StopPlaybackAndResetController(int object) {
    ResourceHandle_ReplaceValueAndInvalidateFileIndices(object, 0, 0);
    Bgm_StopActiveSequenceUnlessBlocked(object, 0);
    Sound_UpdatePlaybackAndFlushCommands();
    ResourceHandle_RestoreSavedArchiveHeapState(object);
    *(int *)(object + 0xb0) = 0;
    *(int *)(object + 0xb4) = 0;
    *(short *)(object + 0xb8) = -1;
    ResourceHandle_InitializeSequenceHandle(object + 0xbc);
    *(short *)(object + 0xba) = -1;
    ResourceHandle_InitializeSequenceHandle(object + 0xc0);
    Bgm_SetPlaybackVolumeAndFade(object, 0x7f, 0);
}
