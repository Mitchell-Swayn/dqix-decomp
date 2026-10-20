#include <globaldefs.h>
// func_02088dc8: 0x02088dc8–0x02088dd8, arm; 16 bytes
// Original: arm9/main @ 0x02088DC8; symbol: func_02088dc8; size: 0x10.
extern "C" void CombatantState_ClearPincushionActionPending(int self) {
    *(unsigned int*)(self + 0x18) &= ~0x20u;
}
