#include "std_library_functions.h"

struct RecordState
{
    unsigned char unknown_00[0x10];
    signed char unknown_10;
    unsigned char unknown_11[3];
};

// Original: arm9/main @ 0x020865EC; symbol: func_020865ec; size: 0x20.
extern "C" void PartyTransfer_ResetSnapshot(RecordState* object)
{
    memset(object, 0, sizeof(*object));
    object->unknown_10 = -1;
}
