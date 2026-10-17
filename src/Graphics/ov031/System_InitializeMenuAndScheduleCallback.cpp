#include <globaldefs.h>
extern "C" void Graphics_LoadMainBG2ScreenAndSetFiveBackgroundPriorities();
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void func_ov031_02222b0c(int);
extern "C" void CreateIndexedRecordAndCallbackState(int);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void Ov031_SetDisplayPlaneAndCallback();
// Original: arm9/ov031 @ 0x02229774; symbol: func_ov031_02229774; size: 0x38.
extern "C" void System_InitializeMenuAndScheduleCallback() {
    Graphics_LoadMainBG2ScreenAndSetFiveBackgroundPriorities();
    Graphics_SubmitIndexedConfiguredBuffer(0x1e);
    func_ov031_02222b0c(0);
    CreateIndexedRecordAndCallbackState(1);
    System_ResolveGlobalGroupEntry(0xb);
    SetMainLoopCallback(Ov031_SetDisplayPlaneAndCallback);
}
