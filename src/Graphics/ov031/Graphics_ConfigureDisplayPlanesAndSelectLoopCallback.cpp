#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290c74[];
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" int IsGlobalControlAbsentOrByte19Clear();
extern "C" void func_ov031_0223c7c4(int);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void ClearDisplayPlaneMask(unsigned,unsigned);
extern "C" void SetSharedWords10And14(unsigned,unsigned);
extern "C" void SetMainLoopCallback(void(*)());
extern "C" void func_ov031_0222905c();
extern "C" void System_InitializeMenuWithResetAndCallback();
// Original: arm9/ov031 @ 0x0222A61C; symbol: func_ov031_0222a61c; size: 0xA8.
extern "C" void Graphics_ConfigureDisplayPlanesAndSelectLoopCallback() {
 if(ReadSelectedContextByte9(1)) return;
 if(ReadSelectedContextByte9(0)) return;
 if(!IsGlobalControlAbsentOrByte19Clear()) return;
 func_ov031_0223c7c4(0);
 if(!data_ov031_02290c74[1]) { Overlay_ProcessPendingFlag(); ClearDisplayPlaneMask(1,1); }
 ClearDisplayPlaneMask(0,0x15);
 if(!data_ov031_02290c74[1]) { SetSharedWords10And14(0,1); SetMainLoopCallback(func_ov031_0222905c); }
 else { SetSharedWords10And14(0,1); SetMainLoopCallback(System_InitializeMenuWithResetAndCallback); }
}
