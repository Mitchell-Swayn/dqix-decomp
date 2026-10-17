#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" int IsGlobalControlAbsentOrByte19Clear();
extern "C" void Overlay_ClearFourSharedObjects();
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void Unclassified_FreeArgumentAndUpdateGlobalOwner(unsigned);
extern "C" void ClearDisplayPlaneMask(unsigned,unsigned);
extern "C" void SetSharedWords10And14(unsigned,unsigned);
extern "C" void SetMainLoopCallback(void(*)());
extern "C" void SetMainLoopWordPair(unsigned,unsigned);
extern "C" void func_ov031_02230ef0(unsigned char);
extern "C" void Ov031_InitializeSecondaryTransition();
extern "C" void func_ov031_02232024();
extern "C" void func_ov031_0222aeb4();
extern "C" void Ov031_InitializeMapTransition();
extern "C" void func_ov031_0222ea24();
extern "C" char data_ov031_02290cc8[];
// Original: arm9/ov031 @ 0x02233784; symbol: func_ov031_02233784; size: 0x130.
extern "C" void Network_TransitionMainLoopFromSelectedMode() {
 if(ReadSelectedContextByte9(1))return;
 if(ReadSelectedContextByte9(0))return;
 if(!IsGlobalControlAbsentOrByte19Clear())return;
 Overlay_ClearFourSharedObjects();
 Overlay_ProcessPendingFlag();
 Unclassified_FreeArgumentAndUpdateGlobalOwner(*(unsigned*)(data_ov031_02290cc8+4));
 ClearDisplayPlaneMask(1,1);
 ClearDisplayPlaneMask(0,0x14);
 if(!*(unsigned char*)(data_ov031_02290cc8+2)) {
  SetSharedWords10And14(2,0);
  SetMainLoopCallback(Ov031_InitializeSecondaryTransition);
  return;
 }
 switch(*(signed char*)(data_ov031_02290cc8+1)) {
 case 0:SetSharedWords10And14(2,1);SetMainLoopCallback(func_ov031_02232024);break;
 case 1:SetSharedWords10And14(2,1);SetMainLoopCallback(func_ov031_0222aeb4);break;
 case 2:SetSharedWords10And14(2,1);SetMainLoopCallback(Ov031_InitializeMapTransition);break;
 case 3:SetSharedWords10And14(2,0);SetMainLoopWordPair(0,0);func_ov031_02230ef0(1);SetMainLoopCallback(func_ov031_0222ea24);break;
 }
}
