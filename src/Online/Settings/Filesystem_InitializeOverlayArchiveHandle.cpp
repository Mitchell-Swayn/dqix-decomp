#include <globaldefs.h>
#include <Filesystem/LowNitroHandle.h>
ARM
extern "C" void* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void* WfcUtility_CreateSteppedPointerRing(unsigned,void*,unsigned);
extern "C" void DisableInterruptsAndHaltForever();
extern "C" unsigned _Z19GenerateLockOwnerIDv();
extern "C" int _Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(NitroVM*,const char*);
extern "C" int _Z16NitroVM_ReadSyncP7NitroVMPvi(NitroVM*,void*,int);
extern "C" void _Z18NitroVM_FinishReadP7NitroVM(NitroVM*);
extern "C" void _Z20SetROMFilesystemRootPKc(const char*);
extern "C" void System_FormatUnboundedString(unsigned,unsigned,...);
extern "C" int Overlay_HandleCardReadCommand(NitroVM*,int);
extern "C" int WfcUtility_ReadUtilityArchiveFromCartridge(NitroHandle*,void*,unsigned,unsigned);
extern "C" int WfcUtility_RejectUtilityArchiveWrite(NitroHandle*,const void*,unsigned,unsigned);
// Original data: arm9/ov031 @ 0x2290d24; symbol: data_ov031_02290d24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage;
extern "C" char Filesystem_InitializeOverlayArchiveHandle_TextRomDwcUtilityBin[],Filesystem_InitializeOverlayArchiveHandle_TextDwc[],Filesystem_InitializeOverlayArchiveHandle_FormatS[];
// Original: arm9/ov031 @ 0x0223B324; symbol: func_ov031_0223b324; size: 0x1B0.
extern "C" void Filesystem_InitializeOverlayArchiveHandle() {
 WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage=(char*)Memory_AllocateZeroedBlock(0xe8,4);
 NitroVM vm;
 NitroVM_Initialize(&vm);
 if(!_Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(&vm,Filesystem_InitializeOverlayArchiveHandle_TextRomDwcUtilityBin)) DisableInterruptsAndHaltForever();
 *(unsigned short*)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+0xe4)=_Z19GenerateLockOwnerIDv();
 void* image=(void*)vm.fileInfo.startOffset;
 unsigned fnt[2];
 unsigned fat[2];
 _Z16NitroVM_ReadSyncP7NitroVMPvi(&vm,fnt,8);
 _Z16NitroVM_ReadSyncP7NitroVMPvi(&vm,fat,8);
 _Z18NitroVM_FinishReadP7NitroVM(&vm);
 NitroHandle_Initialize((NitroHandle*)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+0x88));
 if(!NitroHandle_AddToHandleList((NitroHandle*)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+0x88),Filesystem_InitializeOverlayArchiveHandle_TextDwc,3)) DisableInterruptsAndHaltForever();
 NitroHandle_SetOpcodeOverride((NitroHandle*)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+0x88),Overlay_HandleCardReadCommand,0x602);
 if(!NitroHandle_Populate((NitroHandle*)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+0x88),image,fat[0],fat[1],fnt[0],fnt[1],WfcUtility_ReadUtilityArchiveFromCartridge,WfcUtility_RejectUtilityArchiveWrite)) DisableInterruptsAndHaltForever();
 unsigned size=NitroHandle_LoadFileTables((NitroHandle*)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+0x88),0,0);
 *(void**)WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage=Memory_AllocateZeroedBlock(size,4);
 NitroHandle_LoadFileTables((NitroHandle*)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+0x88),*(void**)WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage,size);
 *(void**)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+0x84)=WfcUtility_CreateSteppedPointerRing(32,WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+4,4);
 char root[128];
 System_FormatUnboundedString((unsigned)root,(unsigned)Filesystem_InitializeOverlayArchiveHandle_FormatS,Filesystem_InitializeOverlayArchiveHandle_TextDwc);
 _Z20SetROMFilesystemRootPKc(root);
}
