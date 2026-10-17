#include <globaldefs.h>
ARM
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv(void);
extern "C" void _ZN11GPCReadPair14ZeroInitializeEv(void *);
extern "C" bool _Z42LoadAndDecompressGPCHeaderAndInnerFileInfoPP7GPCFileR15ExtendedNitroVMPKcPvRjjbPb(void **, void *, const char *, void *, unsigned *, unsigned, bool, bool *);
extern "C" const char data_ov000_02183a2f[];
extern "C" unsigned char data_0211e33c[];
// Original: arm9/ov000 @ 0x02166008; symbol: func_ov000_02166008; size: 0x68.
extern "C" unsigned int LoadOverlayHeaderAndReturnLength(void *unused, void *pair, int releaseAllocations) {
    if (releaseAllocations) {
        _ZN16BackgroundLoader13AddLockGlobalEv();
        _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
    }
    _ZN11GPCReadPair14ZeroInitializeEv(pair);
    unsigned length;
    _Z42LoadAndDecompressGPCHeaderAndInnerFileInfoPP7GPCFileR15ExtendedNitroVMPKcPvRjjbPb((void **)pair, (unsigned char *)pair + 4, data_ov000_02183a2f, data_0211e33c, &length, 0x30000, false, 0);
    return length;
}
