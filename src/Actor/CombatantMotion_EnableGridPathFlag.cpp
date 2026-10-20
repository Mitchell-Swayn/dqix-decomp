#include <globaldefs.h>
// func_020494f8: 0x020494f8–0x0204950c, arm; 20 bytes
// Original: arm9/main @ 0x020494F8; symbol: func_020494f8; size: 0x14.
extern "C" void CombatantMotion_EnableGridPathFlag(int self) {
    int object = *(int*)(self + 0x13c);
        *(unsigned int*)(object + 0x20) |= 0x40;
}
