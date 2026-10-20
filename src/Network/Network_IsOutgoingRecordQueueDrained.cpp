#include <globaldefs.h>
extern "C" {
void System_PushInterruptFourEnabledStateAndDisable(void);
void *Network_GetConnectionManager(void);
int Network_IsRecordQueueEmpty(void *);
int Network_GetLocalMemberPacket(int);
void Interrupts_UpdateTimerOneFromShiftingGlobalMask(void);
// Original: arm9/main @ 0x0205E488; symbol: func_0205e488; size: 0x70.
ARM int Network_IsOutgoingRecordQueueDrained(void *param_1) {
    System_PushInterruptFourEnabledStateAndDisable();
    int result = 0;
    void *state = Network_GetConnectionManager();
    if (Network_IsRecordQueueEmpty((char *)param_1 + 0x150c)) {
        result = 1;
        unsigned char *items = (unsigned char *)Network_GetLocalMemberPacket((int)state);
        for (int i = 0; i < 5; ++i) {
            if ((items + i * 0x14)[0x10] != 0xff) { result = 0; break; }
        }
    }
    Interrupts_UpdateTimerOneFromShiftingGlobalMask();
    return result;
}
}
