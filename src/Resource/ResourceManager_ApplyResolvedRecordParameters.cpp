#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" char *GetBoundedRelocatedBlobIndexEntryFromHeader8(void *);
extern "C" void InitializeGroupResultFromHeaderAndImageOptions(void *, unsigned char, unsigned short, unsigned char, void *, void *);
// Original: arm9/main @ 0x020BE760; symbol: func_020be760; size: 0x48.
extern "C" int ResourceManager_ApplyResolvedRecordParameters(void *object, void *arg) {
    char *result = GetBoundedRelocatedBlobIndexEntryFromHeader8(arg);
    if (result == 0) return 0;
    InitializeGroupResultFromHeaderAndImageOptions(object, (unsigned char)result[9], *(unsigned short *)(result + 4), (unsigned char)result[8], result, arg);
}
