#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e6a0; symbol: data_ov031_0224e6a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned CRC16_ComputeWithInitialZero(void*,void*,unsigned);
extern "C" void WfcUtility_WriteSettingsStorageUntilAccepted(unsigned,unsigned,void*);
extern "C" int Network_ValidateAndCompareByteRange(const void*,const void*,unsigned,const void*);
extern "C" int WfcUtility_FinalizeSettingsStorageTransfer();
// Original: arm9/ov031 @ 0x0221B0AC; symbol: Network_SendFourCRCProtectedBlocksUntilVerified; size: 0x94.
// Appends CRC16 to four FE-byte payloads and retries IPC transfer until compared blocks verify.
extern "C" bool Network_SendFourCRCProtectedBlocksUntilVerified(char* self) {
 int i=0;unsigned destination=*(unsigned*)(WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage+8);char* block=self;
 do{*(unsigned short*)(self+256*i+254)=CRC16_ComputeWithInitialZero(self+0x500,block,254);
 do {WfcUtility_WriteSettingsStorageUntilAccepted(destination,256,block);}while(!Network_ValidateAndCompareByteRange(block,(void*)destination,256,self+0x400));
 block+=256;destination+=256;++i;}while(i<4);
 return WfcUtility_FinalizeSettingsStorageTransfer()!=0;
}
