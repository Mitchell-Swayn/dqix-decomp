#include "GameState/GameState.h"

#if defined(usa)

// Original: arm9/main @ 0x02011FB4; symbol: func_02011fb4; size: 0x3C.
extern "C" bool NativeIdentity_CompareSixBytes(const NativeIdentity* source, NativeIdentity identity)
{
    for (int i = 0; i < 6; ++i) {
        if (identity.bytes_[i] != source->bytes_[i])
            return false;
    }
    return true;
}

#endif
