#include <globaldefs.h>
ARM
struct TPCalibration { short x0,y0,xDotSize,yDotSize; };
struct Sample { unsigned short x,y,valid,other; };
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" int System_ReadTouchCalibrationFromSharedSettings(TPCalibration* out);
extern "C" void TP_SetCalibrateParam(int);
extern "C" void IPC_InitializeSampleBufferAndSendCommand(unsigned command,unsigned mode,Sample *samples,unsigned count);
extern "C" void WaitForGlobalMaskBitsToClear(unsigned int mask);
extern "C" unsigned int TestFieldBitsAtOffset38(unsigned int mask);
extern "C" Sample* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void Math_InitializeDivisionAndInverseSupport();
extern "C" Sample *data_ov031_02290d40[];
// Original: arm9/ov031 @ 0x0223CFF0; symbol: func_ov031_0223cff0; size: 0x7C.
extern "C" void Input_InitializeCalibratedTouchSampling(void) {
    data_ov031_02290d40[1] = Memory_AllocateZeroedBlock(0x3a,4);
    TPCalibration calibration;
    if (!System_ReadTouchCalibrationFromSharedSettings(&calibration)) DisableInterruptsAndHaltForever();
    TP_SetCalibrateParam((int)&calibration);
    IPC_InitializeSampleBufferAndSendCommand(0,4,data_ov031_02290d40[1],5);
    WaitForGlobalMaskBitsToClear(2);
    if (TestFieldBitsAtOffset38(2)) DisableInterruptsAndHaltForever();
    Math_InitializeDivisionAndInverseSupport();
}
