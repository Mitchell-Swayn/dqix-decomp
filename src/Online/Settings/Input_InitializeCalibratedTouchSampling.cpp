#include <globaldefs.h>
ARM
struct TPCalibration { short x0,y0,xDotSize,yDotSize; };
struct Sample { unsigned short x,y,valid,other; };
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" int System_ReadTouchCalibrationFromSharedSettings(TPCalibration* out);
extern "C" void TP_SetCalibrateParam(int);
extern "C" void IPC_InitializeSampleBufferAndSendCommand(unsigned command,unsigned mode,Sample *samples,unsigned count);
extern "C" void TP_WaitBusy(unsigned int mask);
extern "C" unsigned int TP_CheckError(unsigned int mask);
extern "C" Sample* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void Math_InitializeDivisionAndInverseSupport();
// Original data: arm9/ov031 @ 0x2290d40; symbol: data_ov031_02290d40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Sample *WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0223CFF0; symbol: func_ov031_0223cff0; size: 0x7C.
extern "C" void Input_InitializeCalibratedTouchSampling(void) {
    WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage[1] = Memory_AllocateZeroedBlock(0x3a,4);
    TPCalibration calibration;
    if (!System_ReadTouchCalibrationFromSharedSettings(&calibration)) DisableInterruptsAndHaltForever();
    TP_SetCalibrateParam((int)&calibration);
    IPC_InitializeSampleBufferAndSendCommand(0,4,WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage[1],5);
    TP_WaitBusy(2);
    if (TP_CheckError(2)) DisableInterruptsAndHaltForever();
    Math_InitializeDivisionAndInverseSupport();
}
