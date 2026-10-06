#include <globaldefs.h>

struct Function02048c50FlagStorage
{
    unsigned char unknown_000[0x20];
    unsigned int flags_020;
};

struct Function02048c50Owner
{
    unsigned char unknown_000[0x13c];
    Function02048c50FlagStorage* storage_13c;
};

extern "C" void func_02048c50(Function02048c50Owner* owner)
{
    Function02048c50FlagStorage* storage = owner->storage_13c;
    if (storage != NULL)
        storage->flags_020 &= ~0x100u;
}
