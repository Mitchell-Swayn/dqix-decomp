#include <globaldefs.h>
// func_02088af0: 0x02088af0–0x02088b00, arm; 16 bytes
// Original: arm9/main @ 0x02088AF0; symbol: func_02088af0; size: 0x10.
extern "C" void CombatantState_ClearMistMe(int self) {
    *(unsigned int*)(self + 0x14) &= ~0x200000u;
}
