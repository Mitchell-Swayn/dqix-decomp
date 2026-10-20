#include <globaldefs.h>
ARM
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv(void);
extern "C" void _ZN11GPCReadPair14ZeroInitializeEv(void *);
extern "C" bool _Z42LoadAndDecompressGPCHeaderAndInnerFileInfoPP7GPCFileR15ExtendedNitroVMPKcPvRjjbPb(void **, void *, const char *, void *, unsigned *, unsigned, bool, bool *);
extern "C" const char LoadOverlayHeaderAndReturnLength_PathDataPackLv5EnemyGp2[];
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
// Original: arm9/ov000 @ 0x02166008; symbol: func_ov000_02166008; size: 0x68.
extern "C" unsigned int LoadOverlayHeaderAndReturnLength(void *unused, void *pair, int releaseAllocations) {
    if (releaseAllocations) {
        _ZN16BackgroundLoader13AddLockGlobalEv();
        _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
    }
    _ZN11GPCReadPair14ZeroInitializeEv(pair);
    unsigned length;
    _Z42LoadAndDecompressGPCHeaderAndInnerFileInfoPP7GPCFileR15ExtendedNitroVMPKcPvRjjbPb((void **)pair, (unsigned char *)pair + 4, LoadOverlayHeaderAndReturnLength_PathDataPackLv5EnemyGp2, Main_UnknownRoleZeroInitializedStorage_Variant6, &length, 0x30000, false, 0);
    return length;
}
