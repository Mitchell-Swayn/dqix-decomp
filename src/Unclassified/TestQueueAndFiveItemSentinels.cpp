#include <globaldefs.h>
extern "C" {
void System_PushInterruptFourEnabledStateAndDisable(void);
void *Object_GetGlobalConnectionState(void);
int TestWordZero_Main0205E218(void *);
int Object_GetSubrecordAtOffset7C0(int);
void Interrupts_UpdateTimerOneFromShiftingGlobalMask(void);
// Original: arm9/main @ 0x0205E488; symbol: func_0205e488; size: 0x70.
ARM int TestQueueAndFiveItemSentinels(void *param_1) {
    System_PushInterruptFourEnabledStateAndDisable();
    int result = 0;
    void *state = Object_GetGlobalConnectionState();
    if (TestWordZero_Main0205E218((char *)param_1 + 0x150c)) {
        result = 1;
        unsigned char *items = (unsigned char *)Object_GetSubrecordAtOffset7C0((int)state);
        for (int i = 0; i < 5; ++i) {
            if ((items + i * 0x14)[0x10] != 0xff) { result = 0; break; }
        }
    }
    Interrupts_UpdateTimerOneFromShiftingGlobalMask();
    return result;
}
}
