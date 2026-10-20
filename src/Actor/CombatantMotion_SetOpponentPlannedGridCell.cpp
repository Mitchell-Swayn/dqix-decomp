#include <globaldefs.h>
// func_02049400: 0x02049400–0x02049410, arm; 16 bytes
// Original: arm9/main @ 0x02049400; symbol: func_02049400; size: 0x10.
extern "C" void CombatantMotion_SetOpponentPlannedGridCell(int self, unsigned char value) {
    int object = *(int*)(self + 0x13c);
        if (object != 0) {
            *(unsigned char*)(object + 0x1f) = value;
        }
}
