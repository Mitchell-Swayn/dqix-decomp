#include <globaldefs.h>

struct Function0204a5dcObject
{
    unsigned char unknown_000[0x220];
    unsigned int value_220;
};

extern "C" ARM void func_0204a5dc(Function0204a5dcObject* object, unsigned int value)
{
    object->value_220 = value;
}
