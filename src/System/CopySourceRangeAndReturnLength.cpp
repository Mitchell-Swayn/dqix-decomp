#include <globaldefs.h>

#include <System/Memory.h>
struct Owner { char unknown[0xa4]; const char* source; };

// Original: arm9/main @ 0x020C013C; symbol: func_020c013c; size: 0x1C.
extern "C" ARM unsigned CopySourceRangeAndReturnLength(Owner* object, void* destination, unsigned length, int offset) {
    MI_CpuCopy8(object->source+offset, destination, length);
    return length;
}
