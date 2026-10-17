#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int FindKeyAmongFourRecords(void);
extern "C" void Object_GetGlobalConnectionState(void);
extern "C" int TestInactiveOrPrimaryIndexState(void);
extern "C" void InitializeQueuedRecordOwner(unsigned int, int);
// Original: arm9/main @ 0x0207DB58; symbol: func_0207db58; size: 0x50.
extern "C" int InitializeRecordOwnerIfNegative(unsigned int unused, unsigned int param_2, unsigned int param_3) {
    int value = FindKeyAmongFourRecords();
    if (value == 0) return -1;
    if (*(signed char *)(value + 4) < 0) {
        *(unsigned char *)(value + 4) = (unsigned char)param_3;
        Object_GetGlobalConnectionState();
        if (TestInactiveOrPrimaryIndexState() != 0)
            InitializeQueuedRecordOwner(param_2, *(signed char *)(value + 4));
    }
    return *(signed char *)(value + 4);
}
