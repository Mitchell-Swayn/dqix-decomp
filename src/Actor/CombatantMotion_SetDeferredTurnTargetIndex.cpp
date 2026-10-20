#include <globaldefs.h>
// func_0204a030: 0x0204a030–0x0204a040, arm; 16 bytes
// Original: arm9/main @ 0x0204A030; symbol: func_0204a030; size: 0x10.
extern "C" void CombatantMotion_SetDeferredTurnTargetIndex(int self, unsigned char value) {
    int object = *(int*)(self + 0x13c);
        if (object != 0) {
            *(unsigned char*)(object + 0x6c) = value;
        }
}
