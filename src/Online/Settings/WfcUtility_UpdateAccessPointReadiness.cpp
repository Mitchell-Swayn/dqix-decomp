#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
// Original data: arm9/ov031 @ 0x2290cbc; symbol: data_ov031_02290cbc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
struct Shared {unsigned char state,pad;unsigned short timer;};extern "C" Shared WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_StopSequenceImmediately();
extern "C" unsigned Network_CountRecordsWithDifferentHeader(void**);
extern "C" void WfcUtility_CreateSlidingDialog(int,int,int,int,int);
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_DisableBottomButtonTouch();
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void System_EnterModeSixAndInstallCallbackWhenSharedObjectAbsent();extern "C" void System_SetSharedContextAndInstallThirdCallback();
// Original: arm9/ov031 @ 0x02232204; symbol: Network_AdvanceTimedRecordReadiness.
extern "C" void WfcUtility_UpdateAccessPointReadiness(){
WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage.timer++;
if(WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage.timer<300)return;
WfcUtility_StopSequenceImmediately();void* records;
int n=Network_CountRecordsWithDifferentHeader(&records);
if(n==0){WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage.state=2;WfcUtility_CreateSlidingDialog(15,1,1,-1,0);WfcUtility_PlaySequenceArchiveEntry(18);WfcUtility_DisableBottomButtonTouch();WfcUtility_SetMainLoopCallback(System_EnterModeSixAndInstallCallbackWhenSharedObjectAbsent);return;}
int i=0;if(n>0){unsigned char* r=(unsigned char*)records;do {if(r[40]!=2)break;++i;r+=42;}while(i<n);}
if(i==n){WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage.state=3;WfcUtility_CreateSlidingDialog(14,1,1,-1,0);WfcUtility_PlaySequenceArchiveEntry(18);WfcUtility_DisableBottomButtonTouch();WfcUtility_SetMainLoopCallback(System_EnterModeSixAndInstallCallbackWhenSharedObjectAbsent);return;}
WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage.state=1;WfcUtility_PlaySequenceArchiveEntry(15);WfcUtility_SetMainLoopCallback(System_SetSharedContextAndInstallThirdCallback);
}
