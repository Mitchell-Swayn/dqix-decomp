#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" int Unclassified_IsGlobalObjectMissingOrByte18Zero();
extern "C" void func_ov031_0223c7c4(int);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void ClearDisplayPlaneMask(unsigned,unsigned);
extern "C" void SetSharedWords10And14(unsigned,unsigned);
extern "C" void ReadOptionalSharedWords18And1C(unsigned*,unsigned*);
extern "C" void SetMainLoopWordPair(unsigned,unsigned);
extern "C" void SetMainLoopCallback(void(*)());
extern "C" void func_ov031_0222ea24();
extern "C" void func_ov031_02228024();
// Original: arm9/ov031 @ 0x02233FAC; symbol: func_ov031_02233fac; size: 0xA4.
extern "C" void Graphics_TransitionDisplayAndSelectStoredWordCallback() {
 if(ReadSelectedContextByte9(1)) return;
 if(ReadSelectedContextByte9(0)) return;
 if(!Unclassified_IsGlobalObjectMissingOrByte18Zero()) return;
 func_ov031_0223c7c4(0);
 Overlay_ProcessPendingFlag();
 ClearDisplayPlaneMask(1,1);
 ClearDisplayPlaneMask(0,0x15);
 SetSharedWords10And14(2,1);
 unsigned word;
 ReadOptionalSharedWords18And1C(0,&word);
 if(!word) {
  SetMainLoopWordPair(0,0);
  SetMainLoopCallback(func_ov031_0222ea24);
 } else SetMainLoopCallback(func_ov031_02228024);
}
