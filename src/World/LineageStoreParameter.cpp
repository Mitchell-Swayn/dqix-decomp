#include "Resource/Script.h"

struct UnknownPointerSlot
{
    unsigned char unknown_00[0x10];
    void* state;
};
extern UnknownPointerSlot data_020fdc4c;

// The literal names a global slot containing a pointer; the pointed record's
// field at offset 0x14 has no established semantic name.
// Original: arm9/main @ 0x0201F844; symbol: func_0201f844; size: 0x20.
extern "C" int Script_SetStateWordAtOffset14(Script::Parameter* parameter)
{
    int value = parameter->ToInt();
    *(int*)((unsigned char*)data_020fdc4c.state + 0x14) = value;
    return 1;
}
