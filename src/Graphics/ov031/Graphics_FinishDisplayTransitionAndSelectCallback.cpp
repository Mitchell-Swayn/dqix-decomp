#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void Overlay_ClearFourSharedObjects();
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void Unclassified_FreeArgumentAndUpdateGlobalOwner(void*);
extern "C" void ClearDisplayPlaneMask(unsigned,unsigned);
extern "C" void SetSharedWords10And14(unsigned,unsigned);
extern "C" void SetMainLoopCallback(void(*)());
extern "C" void Ov031_InitializeSecondaryTransition();
extern "C" void func_ov031_0222905c();
extern "C" char data_ov031_02290c50[];
// Original: arm9/ov031 @ 0x02228444; symbol: func_ov031_02228444; size: 0xA8.
extern "C" void Graphics_FinishDisplayTransitionAndSelectCallback() {
if(ReadSelectedContextByte9(1)) return;
if(ReadSelectedContextByte9(0)) return;
Overlay_ClearFourSharedObjects();
Overlay_ProcessPendingFlag();
Unclassified_FreeArgumentAndUpdateGlobalOwner(*(void**)(data_ov031_02290c50+4));
ClearDisplayPlaneMask(1,1);
ClearDisplayPlaneMask(0,20);
switch(*(unsigned char*)data_ov031_02290c50) {
case 0:SetSharedWords10And14(1,0);SetMainLoopCallback(Ov031_InitializeSecondaryTransition);break;
case 1:SetSharedWords10And14(0,0);SetMainLoopCallback(func_ov031_0222905c);break;
}
}
