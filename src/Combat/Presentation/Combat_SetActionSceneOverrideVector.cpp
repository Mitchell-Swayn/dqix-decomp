#include <globaldefs.h>
ARM
struct Vector3i { int x, y, z; };
extern "C" void *BattleScene_GetActiveInstance();
extern "C" void _ZN8Vector3iaSERKS_(void *, const void *);

// Original: arm9/ov025 @ 0x021E8748; symbol: func_ov025_021e8748; size: 0x50.
extern "C" int Combat_SetActionSceneOverrideVector(void *object) {
    void *overlay = BattleScene_GetActiveInstance();
    if (overlay != 0) {
        Vector3i value = *(Vector3i *)((unsigned char *)object + 8);
        _ZN8Vector3iaSERKS_((unsigned char *)overlay + 0x6fdc, &value);
        *((unsigned char *)overlay + 0x6fe8) = 1;
    }
    return 1;
}
