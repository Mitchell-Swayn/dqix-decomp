#include <globaldefs.h>
// func_0204947c: 0x0204947c–0x0204948c, arm; 16 bytes
// Original: arm9/main @ 0x0204947C; symbol: func_0204947c; size: 0x10.
extern "C" void CombatantMotion_SetFallbackTargetIndex(int self, unsigned char value) {
    int object = *(int*)(self + 0x13c);
        if (object != 0) {
            *(unsigned char*)(object + 0x4d) = value;
        }
}
