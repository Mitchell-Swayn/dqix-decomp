#include <globaldefs.h>
extern "C" void TouchInput_ResetTrackingState(void);
extern "C" void TouchInput_InitializeIPCHandler(void);
extern "C" int System_ReadTouchCalibrationFromSharedSettings(int);
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void TP_SetCalibrateParam(int);
extern "C" void Input_ConfigureSamplingAndSynchronizePendingValues(int);
extern int data_020fb3cc;

// Original: arm9/main @ 0x0201282C; symbol: func_0201282c; size: 0x70.
extern "C" void InitializeGlobalOwnerAndEmbeddedInputState(int object) {
    data_020fb3cc = object;
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
