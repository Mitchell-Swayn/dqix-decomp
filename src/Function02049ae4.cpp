#include <globaldefs.h>

struct Function02049ae4Inner
{
    unsigned char unknown_000[0x20];
    unsigned int flags_020;
};

struct Function02049ae4Object
{
    unsigned char unknown_000[0x13c];
    Function02049ae4Inner* inner_13c;
};

extern "C" void func_02049ae4(Function02049ae4Object* object)
{
    Function02049ae4Inner* inner = object->inner_13c;
    if (inner != 0)
        inner->flags_020 &= ~4u;
}
