#include <globaldefs.h>

struct AlphaTweenEnableStorageView
{
    unsigned char unknown_000[0x13c];
    unsigned char* storage_13c;
};

extern "C" void func_02049f28(AlphaTweenEnableStorageView* owner)
{
    unsigned char* storage = owner->storage_13c;
    if (storage != NULL)
        storage[0x56] = 1;
}
