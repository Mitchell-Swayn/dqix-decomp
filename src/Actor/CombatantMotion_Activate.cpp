#include <globaldefs.h>
// func_02049f28: 0x02049f28–0x02049f3c, arm; 20 bytes
// Original: arm9/main @ 0x02049F28; symbol: func_02049f28; size: 0x14.
extern "C" void CombatantMotion_Activate(int self) {
    int object = *(int*)(self + 0x13c);
        if (object != 0) {
            *(unsigned char*)(object + 0x56) = 1;
        }
}
