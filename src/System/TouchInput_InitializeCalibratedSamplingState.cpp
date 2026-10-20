#include <globaldefs.h>
extern "C" void TouchInput_ResetTrackingState(void);
extern "C" void TouchInput_InitializeIPCHandler(void);
extern "C" int System_ReadTouchCalibrationFromSharedSettings(int);
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void TP_SetCalibrateParam(int);
extern "C" void Input_ConfigureSamplingAndSynchronizePendingValues(int);
// Original data: arm9/main @ 0x20fb3cc; symbol: data_020fb3cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int TouchInputClearResumePendingOnSample_UnknownRoleZeroInitializedStorage;

// Original: arm9/main @ 0x0201282C; symbol: func_0201282c; size: 0x70.
extern "C" void TouchInput_InitializeCalibratedSamplingState(int object) {
    TouchInputClearResumePendingOnSample_UnknownRoleZeroInitializedStorage = object;
    TouchInput_ResetTrackingState();
    *(unsigned char *)(object + 0x61) = 1;
    TouchInput_InitializeIPCHandler();
    if (System_ReadTouchCalibrationFromSharedSettings(object + 0x28) == 0) {
        DisableInterruptsAndHaltForever();
    }
    TP_SetCalibrateParam(object + 0x28);
    Input_ConfigureSamplingAndSynchronizePendingValues(object);
    *(unsigned char *)(object + 0x60) = 0;
    *(int *)(object + 0x64) = 0;
    *(int *)(object + 0x68) = -1;
    *(int *)(object + 0x6c) = -1;
    *(unsigned char *)(object + 0x62) = 0;
    *(int *)(object + 0x30) = -1;
    *(int *)(object + 0x34) = -1;
}
