#include <globaldefs.h>
ARM
extern "C" void* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void* WfcUtility_CreateSteppedPointerRing(int,void*,int);
extern "C" void* System_InitializeGlobalQueue();
extern "C" void WfcUtility_PrependListNode(void*,void*);
extern "C" void WfcUtility_AppendListNode(void*,void*);
// Original data: arm9/ov031 @ 0x2290d64; symbol: data_ov031_02290d64.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223DABC; symbol: func_ov031_0223dabc; size: 0xC0.
extern "C" void Resource_AllocateAndInitializeTwoStateBlocks(){
 UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage=(unsigned char*)Memory_AllocateZeroedBlock(0x340,4);
 for(int i=0;i<2;i++){
 int offset=i*0x1a0;
 *(void**)(UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage+offset+0x19c)=WfcUtility_CreateSteppedPointerRing(32,UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage+offset,12);
 *(void**)(UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage+offset+0x198)=System_InitializeGlobalQueue();
 *(unsigned short*)(UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage+offset+0x188)=0x300;
 *(unsigned short*)(UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage+offset+0x194)=0x400;
 WfcUtility_PrependListNode(*(void**)(UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage+offset+0x198),UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage+offset+0x180);
 WfcUtility_AppendListNode(*(void**)(UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage+offset+0x198),UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage+offset+0x18c);
 }
}
