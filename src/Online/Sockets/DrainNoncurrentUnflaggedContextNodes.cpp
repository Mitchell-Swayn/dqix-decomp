#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e1cc; symbol: data_ov031_0224e1cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e22c; symbol: data_ov031_0224e22c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e230; symbol: data_ov031_0224e230.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* DrainNoncurrentUnflaggedContextNodes_UnknownRoleZeroInitializedStorage;extern "C" char* NetworkRegisterActiveSocket_UnknownRoleZeroInitializedStorage;extern "C" unsigned NetworkDestroyClosedSockets_UnknownRoleZeroInitializedStorage;extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" void Network_RequestSocketClose(void*);
// Original: arm9/ov031 @ 0x02206CE8; symbol: DrainNoncurrentUnflaggedContextNodes; size: 0xA8.
// Drains noncurrent context nodes without flag10 while protecting list selection against IRQs.
extern "C" int DrainNoncurrentUnflaggedContextNodes(){char* node;for(;;){int irq=_Z20DisableIRQInterruptsv();node=NetworkRegisterActiveSocket_UnknownRoleZeroInitializedStorage;if(node){char* current=DrainNoncurrentUnflaggedContextNodes_UnknownRoleZeroInitializedStorage;do{if(node!=current && !(*(short*)(node+0x70)&0x10))break;node=*(char**)(node+0x7c);}while(node);}_Z20SetIRQInterruptStatei(irq);if(!node)break;Network_RequestSocketClose(node);}char* head=NetworkRegisterActiveSocket_UnknownRoleZeroInitializedStorage;if(!head || (head==DrainNoncurrentUnflaggedContextNodes_UnknownRoleZeroInitializedStorage && !*(void**)(head+0x7c))){if(!NetworkDestroyClosedSockets_UnknownRoleZeroInitializedStorage)return 0;}return -26;}
