#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5d8; symbol: data_ov031_0224e5d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage;
extern "C" void WirelessBeaconScan_HandleExtendedScanResults();
extern "C" unsigned WM_GetAllowedChannel();
extern "C" unsigned short WM_GetDispersionScanPeriod();
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" int Network_StartExtendedScan(void*,void*);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x022160B0; symbol: Network_InitializeAndStartExtendedScan; size: 0xc8.
// Initializes shared scan buffer, checksum, wildcard address and callback before extended scan.
extern "C" int Network_InitializeAndStartExtendedScan(void* callback){if(!callback)return -1;P(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage,0x1300)=UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage+0xf00;H(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage,0x1304)=0x400;H(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage,0x1306)=WM_GetAllowedChannel();H(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage,0x1308)=WM_GetDispersionScanPeriod();H(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage,0x1310)=1;VectorizedMemset(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage+0x130a,255,6);P(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage,0x1344)=(char*)callback;W(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage,0x1a90)=1;int result=Network_StartExtendedScan((void*)WirelessBeaconScan_HandleExtendedScanResults,UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage+0x1300);if(result==2)result=0;return result;}
