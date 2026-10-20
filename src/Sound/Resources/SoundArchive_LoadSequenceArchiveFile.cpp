#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int NNS_SndArcGetFileAddress(void);
extern "C" int NNS_SndArcGetCurrent(void);
extern "C" int Filesystem_AllocateReadAndFlushFileBuffer(void *, void *, void *, void *, void *);
extern "C" void NNS_SndArcSetFileAddress(void *, int);
extern "C" void SoundArchive_DisposeSequenceFile(void);
// Original: arm9/main @ 0x020BE1A8; symbol: func_020be1a8; size: 0x6C.
extern "C" int SoundArchive_LoadSequenceArchiveFile(void *param1, void *param2, int param3) {
    int result = NNS_SndArcGetFileAddress();
    if (result == 0) {
        int secondary = param3 != 0 ? NNS_SndArcGetCurrent() : 0;
        result = Filesystem_AllocateReadAndFlushFileBuffer(param1, (void *)SoundArchive_DisposeSequenceFile, (void *)secondary, param1, param2);
        if (param3 != 0 && result != 0) NNS_SndArcSetFileAddress(param1, result);
    }
    return result;
}
