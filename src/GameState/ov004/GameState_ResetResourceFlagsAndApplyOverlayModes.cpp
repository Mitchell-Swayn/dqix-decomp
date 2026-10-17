#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" unsigned GameState_ReadByteAtOffset4(void*);
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(void*,unsigned);
extern "C" void InitializeObjectHandlesAndInvalidIndices(void*);
extern "C" void TransferActiveResourceHandleAndInvalidateIndices(char*);
extern "C" void SetModeOneThroughFiveAndRefreshValue(void*,int);
extern "C" void SetStateWithinOneThroughFiveAndDispatch(void*,int);
extern "C" void Flags_ClearWordMask(void*,unsigned);
extern "C" void ClearWordAtOffset4MaskedBits(void*,unsigned);
extern "C" void ClearMaskedFlagsAtOffset8(void*,unsigned);
extern "C" void GameState_SetFlagAtOffset4324(void*);
extern "C" void GameState_SetUnknown7f6c(void*,int);
extern "C" void GameState_SetUnk4Element0(void*,int);
extern "C" unsigned GameState_ReadUnknown7f70(void*);
extern "C" void GameState_WriteUnknownF70(void*,int);
extern "C" void WriteActive(void*);
extern "C" unsigned char data_02109bf4[],data_02108760[],data_ov004_02171034[];
// Original: arm9/ov004 @ 0x0216D920; symbol: func_ov004_0216d920; size: 0x138.
extern "C" int GameState_ResetResourceFlagsAndApplyOverlayModes() {
 void* state=_ZN9GameState11GetInstanceEv();
 void* resources=GameResources_GetInstance();
 if(GameState_ReadByteAtOffset4(state)!=2) {
 DispatchObjectStateOneOrTwoUnlessFlag4(data_02109bf4,0);
 InitializeObjectHandlesAndInvalidIndices(data_02109bf4);
 TransferActiveResourceHandleAndInvalidateIndices((char*)data_02108760);
 }
 SetModeOneThroughFiveAndRefreshValue(data_02109bf4,data_ov004_02171034[4]);
 SetStateWithinOneThroughFiveAndDispatch(data_02108760,data_ov004_02171034[1]);
 Flags_ClearWordMask(resources,~0u);
 ClearWordAtOffset4MaskedBits(resources,~0u);
 ClearMaskedFlagsAtOffset8(resources,~0u);
 GameState_SetFlagAtOffset4324(resources);
 GameState_SetUnknown7f6c(state,5);
 if(data_ov004_02171034[2]==1 && data_ov004_02171034[3]!=4) {
 GameState_SetUnk4Element0(state,6);
 GameState_SetUnknown7f6c(state,2);
 }
 if(GameState_ReadUnknown7f70(state)==1) {
 GameState_SetUnk4Element0(state,6);
 GameState_SetUnknown7f6c(state,0);
 GameState_WriteUnknownF70(state,0);
 }
 if(data_ov004_02171034[5]) { WriteActive(state); data_ov004_02171034[5]=0; }
 return 0;
}
