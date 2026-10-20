#include <globaldefs.h>
// func_02049458: 0x02049458–0x02049468, arm; 16 bytes
// Original: arm9/main @ 0x02049458; symbol: func_02049458; size: 0x10.
extern "C" void CombatantMotion_SetPrimaryTargetIndex(int self, unsigned char value) {
    int object = *(int*)(self + 0x13c);
        if (object != 0) {
            *(unsigned char*)(object + 0x4c) = value;
        }
}
