#include <globaldefs.h>

extern "C" void func_02048150(void*, int, int, void*);
struct Owner { char unknown[0x18c]; unsigned flags; };

// Original: arm9/main @ 0x02053FE4; symbol: func_02053fe4; size: 0x1C.
extern "C" ARM void ApplyLimitAndClearFlag1(Owner* object, int limit, int notify, void* context) {
    func_02048150(object, limit, notify, context);
    object->flags &= ~1u;
}
