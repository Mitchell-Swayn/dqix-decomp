#include <globaldefs.h>
ARM
extern "C" void *data_ov031_0224e580;
extern "C" int StoreReadySharedValue(void (*)(void));
extern "C" int System_CompareWordToGlobalResult(void *);
extern "C" void WaitForSharedObjectWord2C(void);
extern "C" void Unclassified_ResetStateAndSetFlags(void);
extern "C" void Unclassified_EnsureD6RecordState(void);
// Original: arm9/ov031 @ 0x0220FD78; symbol: func_ov031_0220fd78; size: 0x74.
extern "C" void System_InitializeYSSDRequestAndWait(int input, unsigned char *request) {
    *(unsigned int *)(request + 0) = 0x14;
    *(const unsigned int **)(request + 4) = (const unsigned int *)0x44535359;
    *(unsigned int *)(request + 8) = 0xd5;
    *(unsigned int *)(request + 0xc) = 1;
    *(unsigned int *)(request + 0x10) = input;
    *(unsigned int *)((unsigned char *)data_ov031_0224e580 + 0x30) = 0;
    if (StoreReadySharedValue(Unclassified_EnsureD6RecordState)) {
        if (System_CompareWordToGlobalResult(request)) WaitForSharedObjectWord2C();
    }
    Unclassified_ResetStateAndSetFlags();
}
