#include "System/Memory.h"

// Read bytes from the caller-owned input cursor, then advance it by the same
// count. Callers use stack cursors while decoding variable-length records.
extern "C" void func_0200fd14(const unsigned char** cursor, void* destination,
                              unsigned int length)
{
    VectorizedInvertedMemcpy(*cursor, destination, length);
    *cursor += length;
}
