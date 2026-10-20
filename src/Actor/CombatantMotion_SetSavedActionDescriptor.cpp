#include <globaldefs.h>
// func_0204a00c: 0x0204a00c–0x0204a01c, arm; 16 bytes
// Original: arm9/main @ 0x0204A00C; symbol: func_0204a00c; size: 0x10.
extern "C" void CombatantMotion_SetSavedActionDescriptor(int self, unsigned int value) {
    int object = *(int*)(self + 0x13c);
        if (object != 0) {
            *(unsigned int*)(object + 0x68) = value;
        }
}
