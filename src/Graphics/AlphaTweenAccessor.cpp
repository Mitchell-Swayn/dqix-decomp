#include "Graphics/AlphaTween.h"
#include <globaldefs.h>

struct AlphaTweenStorageView
{
    unsigned char unknown_000[0x13c];
    const unsigned char* storage_13c;
};

extern "C" float func_02049fec(const AlphaTweenStorageView* owner)
{
    const unsigned char* storage = owner->storage_13c;
    if (storage == NULL)
        return 0.0f;

    const AlphaTween* tween =
        reinterpret_cast<const AlphaTween*>(storage + 0x60);
    return tween->GetTarget();
}
