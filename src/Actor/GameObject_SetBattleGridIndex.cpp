#include <globaldefs.h>
// func_02049390: 0x02049390–0x020493a4, arm; 20 bytes
// Original: arm9/main @ 0x02049390; symbol: func_02049390; size: 0x14.
extern "C" void GameObject_SetBattleGridIndex(int self, int value) {
    int object = *(int*)(self + 0x13c);
        if (object != 0 && value != 0xff) {
            *(unsigned char*)(object + 0x1c) = (unsigned char)value;
        }
}
