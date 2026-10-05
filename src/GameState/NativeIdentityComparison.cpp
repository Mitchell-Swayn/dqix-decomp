#include "GameState/GameState.h"

#if defined(usa)

extern "C" bool func_02011fb4(const NativeIdentity* source, NativeIdentity identity)
{
    for (int i = 0; i < 6; ++i) {
        if (identity.bytes_[i] != source->bytes_[i])
            return false;
    }
    return true;
}

#endif
