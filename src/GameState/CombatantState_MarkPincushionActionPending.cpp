#include <globaldefs.h>
// func_02088db8: 0x02088db8–0x02088dc8, arm; 16 bytes
// Original: arm9/main @ 0x02088DB8; symbol: func_02088db8; size: 0x10.
extern "C" void CombatantState_MarkPincushionActionPending(int self) {
    *(unsigned int*)(self + 0x18) |= 0x20;
}
