#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290c58[];
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" int IsGlobalControlAbsentOrByte19Clear();
extern "C" void func_ov031_0223c7c4(int);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void ClearDisplayPlaneMask(unsigned,unsigned);
extern "C" void SetSharedWords10And14(unsigned,unsigned);
extern "C" void SetMainLoopCallback(void(*)());
extern "C" void func_ov031_0222905c();
extern "C" void System_InitializeContextAndCallback();
// Original: arm9/ov031 @ 0x02228858; symbol: func_ov031_02228858; size: 0xB8.
extern "C" void Graphics_ConfigureDisplayPlanesForPrimaryContextMode() {
 if(ReadSelectedContextByte9(0)) return;
 if(!data_ov031_02290c58[0] && ReadSelectedContextByte9(1)) return;
 if(!IsGlobalControlAbsentOrByte19Clear()) return;
 func_ov031_0223c7c4(0);
 if(!data_ov031_02290c58[0]) { Overlay_ProcessPendingFlag(); ClearDisplayPlaneMask(1,1); }
 ClearDisplayPlaneMask(0,0x15);
 if(!data_ov031_02290c58[0]) { SetSharedWords10And14(0,1); SetMainLoopCallback(func_ov031_0222905c); }
 else { SetSharedWords10And14(0,1); SetMainLoopCallback(System_InitializeContextAndCallback); }
}
