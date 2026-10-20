#include <globaldefs.h>
ARM
struct GPCReadPair { void Reset(); };
struct BackgroundLoader { static void RemoveLockGlobal(); };
// Original: arm9/ov000 @ 0x0216638C; symbol: func_ov000_0216638c; size: 0x14.
extern "C" void System_ResetReadPairAndRemoveGlobalLock(void *unused, GPCReadPair *pair) {
    pair->Reset();
    BackgroundLoader::RemoveLockGlobal();
}
