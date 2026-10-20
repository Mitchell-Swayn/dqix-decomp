#include <globaldefs.h>
extern "C" void* _Z16GetCombatantByIDii(int, int);
// Original: arm9/ov024 @ 0x021E9990; symbol: func_ov024_021e9990; size: 0x48.
extern "C" ARM int Ov024_GetActionForMissingCombatant(void* owner, int id, int unused, int active, signed char kind) {
    void* manager = *(void**)((char*)owner + 0x10);
    if (!_Z16GetCombatantByIDii((int)manager, id)) return 0;
    if (active) goto done;
    switch (kind) {
        case 2: return 0xc4;
        default: return 0xc5;
    }
done:
    return 0;
}
