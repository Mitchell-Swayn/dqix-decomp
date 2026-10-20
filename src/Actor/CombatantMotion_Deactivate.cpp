#include <globaldefs.h>
// func_02049f3c: 0x02049f3c–0x02049f50, arm; 20 bytes
// Original: arm9/main @ 0x02049F3C; symbol: func_02049f3c; size: 0x14.
extern "C" void CombatantMotion_Deactivate(int self) {
    int object = *(int*)(self + 0x13c);
        if (object != 0) {
            *(unsigned char*)(object + 0x56) = 0;
        }
}
