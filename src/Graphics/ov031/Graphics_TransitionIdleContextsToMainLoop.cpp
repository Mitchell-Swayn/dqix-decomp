#include <globaldefs.h>
ARM
extern "C" { int IsGlobalControlAbsentOrByte19Clear(); void Overlay_ProcessPendingFlag(); void SetMainLoopCallback(void(*)()); void SetSharedWords10And14(unsigned,unsigned); unsigned ReadSelectedContextByte9(int); void func_ov031_0223c7c4(int); void ClearDisplayPlaneMask(unsigned,unsigned); void Ov031_InitializeSecondaryTransition(); void func_ov031_022348cc(); extern unsigned char data_ov031_02290ce0; }
// Original: arm9/ov031 @ 0x022347F4; symbol: func_ov031_022347f4; size: 0xB8.
extern "C" void Graphics_TransitionIdleContextsToMainLoop() {
 if(ReadSelectedContextByte9(0)) return;
 if(!data_ov031_02290ce0 && ReadSelectedContextByte9(1)) return;
 if(!IsGlobalControlAbsentOrByte19Clear()) return;
 func_ov031_0223c7c4(0);
 if(!data_ov031_02290ce0) { Overlay_ProcessPendingFlag(); ClearDisplayPlaneMask(1,1); }
 ClearDisplayPlaneMask(0,21);
 if(!data_ov031_02290ce0) { SetSharedWords10And14(2,1); SetMainLoopCallback(Ov031_InitializeSecondaryTransition); }
 else { SetSharedWords10And14(2,1); SetMainLoopCallback(func_ov031_022348cc); }
}
