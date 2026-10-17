#include <globaldefs.h>
ARM
extern "C" {extern unsigned char data_ov031_02290c6c;int IsGlobalControlAbsentOrByte19Clear();void Overlay_ProcessPendingFlag();void SetMainLoopCallback(void(*)());void SetSharedWords10And14(unsigned,unsigned);unsigned ReadSelectedContextByte9(int);void func_ov031_0223c7c4(int);void ClearDisplayPlaneMask(unsigned,unsigned);void func_ov031_0222905c();void Overlay_InitializeAndInstallCallback();}
// Original: arm9/ov031 @ 0x0222A0BC; symbol: func_ov031_0222a0bc; size: 0xB8.
extern "C" void Graphics_PrepareDisplayAndSelectLoopCallback(){
if(ReadSelectedContextByte9(0))return;
if(!data_ov031_02290c6c){if(ReadSelectedContextByte9(1))return;}
if(!IsGlobalControlAbsentOrByte19Clear())return;
func_ov031_0223c7c4(0);
if(!data_ov031_02290c6c){Overlay_ProcessPendingFlag();ClearDisplayPlaneMask(1,1);}
ClearDisplayPlaneMask(0,0x15);
if(!data_ov031_02290c6c){SetSharedWords10And14(0,1);SetMainLoopCallback(func_ov031_0222905c);}
else{SetSharedWords10And14(0,1);SetMainLoopCallback(Overlay_InitializeAndInstallCallback);}
}
