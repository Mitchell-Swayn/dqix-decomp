#include "System/RuntimeStream.h"

#pragma optimize_for_size off
#pragma dont_inline on

// Original: arm9/main @ 0x0200173C; symbol: func_0200173c; size: 0x68.
extern "C" int Runtime_FlushAllOpenStreams()
{
    RuntimeStream* stream = RuntimeFlushAllOpenStreams_UnknownRoleProcedureReferenceRecords;
    int result = 0;
    int next = 1;
    do {
        if (stream->kind && RuntimeStreamBuffers_FlushStreamOrAllStreams(stream))
            result = -1;
        if (next < 3)
            stream = &RuntimeFlushAllOpenStreams_UnknownRoleProcedureReferenceRecords[next++];
        else
            stream = 0;
    } while (stream);
    return result;
}

