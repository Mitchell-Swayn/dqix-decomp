#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5d8; symbol: data_ov031_0224e5d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage;
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
// Original: arm9/ov031 @ 0x022161B0; symbol: func_ov031_022161b0; size: 0x9C.
extern "C" int WirelessBeaconScan_CopyReadyResult(int index,unsigned char* out) {
 unsigned char* self=UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage;
 if(*(int*)(self+0x1a90)!=2) return -1;
 if(index<0 || index>=*(int*)(self+0x1a88)) return -1;
 VectorizedMemset(out,0,0x78);
 *(unsigned*)out=1;
 *(unsigned short*)(out+4)=*(unsigned short*)(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage+index*2+0x1a48);
 MI_CpuCopy8(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage+0x1348+index*0x70,out+6,0x70);
 return 0;
}
