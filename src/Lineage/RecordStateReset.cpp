#include "std_library_functions.h"

struct RecordState
{
    unsigned char unknown_00[0x10];
    signed char unknown_10;
    unsigned char unknown_11[3];
};

extern "C" void func_020865ec(RecordState* object)
{
    memset(object, 0, sizeof(*object));
    object->unknown_10 = -1;
}
