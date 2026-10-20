#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" char *NNS_SndArcGetSeqInfo(void *);
extern "C" void SoundArchive_StartSequenceWithBank(void *, unsigned char, unsigned short, unsigned char, void *, void *);
// Original: arm9/main @ 0x020BE760; symbol: func_020be760; size: 0x48.
extern "C" int ResourceManager_ApplyResolvedRecordParameters(void *object, void *arg) {
    char *result = NNS_SndArcGetSeqInfo(arg);
    if (result == 0) return 0;
    SoundArchive_StartSequenceWithBank(object, (unsigned char)result[9], *(unsigned short *)(result + 4), (unsigned char)result[8], result, arg);
}
