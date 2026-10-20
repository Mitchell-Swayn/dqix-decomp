#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e6a0; symbol: data_ov031_0224e6a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_WriteSettingsStorageUntilAccepted(unsigned,unsigned,void*);
extern "C" int Network_ValidateAndCompareByteRange(const void*,const void*,unsigned,const void*);
extern "C" int WfcUtility_FinalizeSettingsStorageTransfer();
// Original: arm9/ov031 @ 0x0221B024; symbol: TransferAndValidateFourSelectedPages; size: 0x88.
// Transfers and validates each selected 256-byte page until successful, then waits on the IPC handler.
extern "C" int WfcUtility_WriteAndVerifySelectedSettingsPages(char* data,int* selected,const void* other){
 int i=0;unsigned address=WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[2];
 for(;i<4;i++,data+=256,address+=256){
 if(selected[i]){do{WfcUtility_WriteSettingsStorageUntilAccepted(address,256,data);}while(!Network_ValidateAndCompareByteRange(data,(void*)address,256,other));}}
 return WfcUtility_FinalizeSettingsStorageTransfer()!=0;
}
