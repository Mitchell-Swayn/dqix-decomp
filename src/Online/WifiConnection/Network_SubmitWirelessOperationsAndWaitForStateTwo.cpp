#include <globaldefs.h>
ARM
extern "C" int WirelessCommand_CopyValidatedSharedTwoThousandByteBlock(int);
extern "C" int WirelessCommand_SubmitOpcodeOne(void*);
extern "C" int WM_End(unsigned);
extern "C" void Network_HandleType26ScanReply();
// Original data: arm9/ov031 @ 0x2290cf8; symbol: data_ov031_02290cf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022358E8; symbol: func_ov031_022358e8; size: 0x9C.
extern "C" int Network_SubmitWirelessOperationsAndWaitForStateTwo(){
 WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage[0x1e5c]=1;
 WirelessCommand_CopyValidatedSharedTwoThousandByteBlock((int)(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage+0x168c));
 if(*(unsigned short*)(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage+0x168c)!=2){
 if(WirelessCommand_SubmitOpcodeOne((void*)Network_HandleType26ScanReply)!=2)return 0;
 do{
 WirelessCommand_CopyValidatedSharedTwoThousandByteBlock((int)(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage+0x168c));
 }while(*(unsigned short*)(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage+0x168c)!=2);
 }
 if(WM_End((unsigned)Network_HandleType26ScanReply)!=2)return 0;
 return 1;
}
