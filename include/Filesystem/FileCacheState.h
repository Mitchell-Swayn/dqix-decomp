#pragma once

// One observed byte flag followed by three alignment bytes in the ITCM cache
// storage. This carrier makes the full four-byte allocation explicit.
struct FileCacheReadyFlag
{
    bool ready;
    unsigned char padding[3];
};
