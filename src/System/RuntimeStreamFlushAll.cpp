#include "System/RuntimeStream.h"

#pragma optimize_for_size off
#pragma dont_inline on

extern "C" int func_0200173c()
{
    RuntimeStream* stream = data_020eebe0;
    int result = 0;
    int next = 1;
    do {
        if (stream->kind && func_02001878(stream))
            result = -1;
        if (next < 3)
            stream = &data_020eebe0[next++];
        else
            stream = 0;
    } while (stream);
    return result;
}

