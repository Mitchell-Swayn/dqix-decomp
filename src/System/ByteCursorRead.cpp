#include "System/Memory.h"

// Read bytes from the caller-owned input cursor, then advance it by the same
// count. Callers use stack cursors while decoding variable-length records.
// Original: arm9/main @ 0x0200FD14; symbol: func_0200fd14; size: 0x24.
extern "C" void GameState_CopyBytesAndAdvanceCursor(const unsigned char** cursor, void* destination,
                              unsigned int length)
{
    MI_CpuCopy8(*cursor, destination, length);
    *cursor += length;
}
