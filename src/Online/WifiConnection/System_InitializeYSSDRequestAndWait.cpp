#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" int StoreReadySharedValue(void (*)(void));
extern "C" int System_CompareWordToGlobalResult(void *);
extern "C" void YssdCommand_WaitForReplyCompletion(void);
extern "C" void YssdCommand_ClearReplyHandler(void);
extern "C" void YssdCommand_RecordInitializationReply(void);
// Original: arm9/ov031 @ 0x0220FD78; symbol: func_ov031_0220fd78; size: 0x74.
extern "C" void System_InitializeYSSDRequestAndWait(int input, unsigned char *request) {
    *(unsigned int *)(request + 0) = 0x14;
    *(const unsigned int **)(request + 4) = (const unsigned int *)0x44535359;
    *(unsigned int *)(request + 8) = 0xd5;
    *(unsigned int *)(request + 0xc) = 1;
    *(unsigned int *)(request + 0x10) = input;
    *(unsigned int *)((unsigned char *)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x30) = 0;
    if (StoreReadySharedValue(YssdCommand_RecordInitializationReply)) {
        if (System_CompareWordToGlobalResult(request)) YssdCommand_WaitForReplyCompletion();
    }
    YssdCommand_ClearReplyHandler();
}
