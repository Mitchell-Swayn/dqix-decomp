#include <globaldefs.h>
THUMB
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void VectorizedMemset(void*,int,unsigned);
// Original data: arm9/ov031 @ 0x2245fb0; symbol: data_ov031_02245fb0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffff0000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2245fb8; symbol: data_ov031_02245fb8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224f620; symbol: data_ov031_0224f620.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224f648; symbol: data_ov031_0224f648.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224f650; symbol: data_ov031_0224f650.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage[],NetworkConfigureSixByteAddressAndPayload_UnknownRoleZeroInitializedStorage[],NetworkConfigureSixByteAddressAndPayload_UnknownRoleZeroInitializedStorage_Variant2[],NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes[],NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes_Variant2[];
extern "C" int Network_RequestScanOrStopScan(void*,void*,unsigned);
extern "C" int Network_StopQueueSessionWirelessOperation();
// Original: arm9/ov031 @ 0x0221F02C; symbol: Network_ConfigureSixByteAddressAndPayload; size: 0xf0.
// Copies optional six-byte address and padded 32-byte payload under IRQ protection, then advances state.
extern "C" int Network_ConfigureSixByteAddressAndPayload(unsigned char *address,unsigned char *payload,int length,unsigned callback){
int i; int irq=_Z20DisableIRQInterruptsv();*(unsigned*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+4)=callback;
 if(address){unsigned char *dst=NetworkConfigureSixByteAddressAndPayload_UnknownRoleZeroInitializedStorage;for(i=0;i<6;++i)*dst++=*address++;*(void**)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+16)=NetworkConfigureSixByteAddressAndPayload_UnknownRoleZeroInitializedStorage;}else{VectorizedMemset(NetworkConfigureSixByteAddressAndPayload_UnknownRoleZeroInitializedStorage,255,6);*(void**)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+16)=NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes;}
 if(payload&&length>0&&length<=32){i=0;for(;i<length;++i)NetworkConfigureSixByteAddressAndPayload_UnknownRoleZeroInitializedStorage_Variant2[i]=*payload++;for(;i<32;++i)NetworkConfigureSixByteAddressAndPayload_UnknownRoleZeroInitializedStorage_Variant2[i]=0;*(void**)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+20)=NetworkConfigureSixByteAddressAndPayload_UnknownRoleZeroInitializedStorage_Variant2;}else{VectorizedMemset(NetworkConfigureSixByteAddressAndPayload_UnknownRoleZeroInitializedStorage_Variant2,255,32);*(void**)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+20)=NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes_Variant2;}
 if(*(int*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+24)==3){if(Network_RequestScanOrStopScan(*(void**)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+16),*(void**)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+20),*(unsigned*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+4))==3){*(int*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+24)=6;_Z20SetIRQInterruptStatei(irq);return 1;}}
 else if(Network_StopQueueSessionWirelessOperation()==1){*(int*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage+24)=6;_Z20SetIRQInterruptStatei(irq);return 1;}
 _Z20SetIRQInterruptStatei(irq);return 0;
}
