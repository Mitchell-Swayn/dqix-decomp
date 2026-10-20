#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char PMGoSleepMode_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020CE240; symbol: func_020ce240; size: 0x30.
    void IPC_ClearPendingAndInvokeCompletionCallback(void *arg){
        void (*callback)(void *,int)=*(void (**)(void *,int))(PMGoSleepMode_UnknownRoleZeroInitializedStorage+32);
        int value=*(int *)(PMGoSleepMode_UnknownRoleZeroInitializedStorage+36);
        *(int *)(PMGoSleepMode_UnknownRoleZeroInitializedStorage+28)=0;
        if(!callback)return;
        *(int *)(PMGoSleepMode_UnknownRoleZeroInitializedStorage+32)=0;
        callback(arg,value);
    }
}
