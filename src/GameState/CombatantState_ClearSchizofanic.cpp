#include <globaldefs.h>
// func_02088aa8: 0x02088aa8–0x02088ab8, arm; 16 bytes
// Original: arm9/main @ 0x02088AA8; symbol: func_02088aa8; size: 0x10.
extern "C" void CombatantState_ClearSchizofanic(int self) {
    *(unsigned int*)(self + 0x14) &= ~0x100000u;
}
