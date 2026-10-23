#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
unsigned long long _Z19GetCurrentTimestampv();
int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
void WfcUtility_RequestTaskRemoval(unsigned,void*);
// Original data: arm9/ov031 @ 0x2290d0c; symbol: data_ov031_02290d0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char* WirelessInitializeUsbAccessPointScan_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2249280; symbol: data_ov031_02249280.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern const unsigned char NetworkClassifyTimedRecordStatus_UnknownRoleInitializedBytes[];
}
typedef void (*StatusCallback)(int);
// Original: arm9/ov031 @ 0x022379F0; symbol: func_ov031_022379f0; size: 0x13C.
extern "C" void Network_ClassifyTimedRecordStatus(void* argument,void*) {
 void* volatile saved=argument;
 unsigned long long now=_Z19GetCurrentTimestampv();
 unsigned char* p=WirelessInitializeUsbAccessPointScan_UnknownRoleZeroInitializedStorage;
 int i,nonzero,zero;
 unsigned char *keys,*scan;
 zero=0;
 if(now<*(unsigned long long*)(p+0x1b88)+0x17f898ULL) return;
 nonzero=zero;
 i=0;
 scan=p;
 keys=p+0x1300;
 for(;i<16;i++,keys+=7,scan+=7) {
  if(RuntimeMemory_CompareByteRanges(keys,NetworkClassifyTimedRecordStatus_UnknownRoleInitializedBytes,6)!=0) {
   if(scan[0x1306]) nonzero=1;
   else zero=1;
  }
 }
 if(nonzero && zero) {
  StatusCallback callback=*(StatusCallback*)(p+0x1370);
  if(callback) callback(2);
 } else if(nonzero) {
  StatusCallback callback=*(StatusCallback*)(p+0x1370);
  if(callback) callback(1);
 } else if(!zero) {
  StatusCallback callback=*(StatusCallback*)(p+0x1370);
  if(callback) callback(0);
 }
 *(unsigned*)(WirelessInitializeUsbAccessPointScan_UnknownRoleZeroInitializedStorage+0x1b90)=0;
 WirelessInitializeUsbAccessPointScan_UnknownRoleZeroInitializedStorage[0x1b96]=1;
 WfcUtility_RequestTaskRemoval(0,saved);
}
