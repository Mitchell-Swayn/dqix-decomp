#include <globaldefs.h>
#include <Filesystem/LowNitroHandle.h>
ARM
extern "C" void* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void* InitializeSteppedOverlayValues(unsigned,void*,unsigned);
extern "C" void DisableInterruptsAndHaltForever();
extern "C" unsigned _Z19GenerateLockOwnerIDv();
extern "C" int _Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(NitroVM*,const char*);
extern "C" int _Z16NitroVM_ReadSyncP7NitroVMPvi(NitroVM*,void*,int);
extern "C" void _Z18NitroVM_FinishReadP7NitroVM(NitroVM*);
extern "C" void _Z20SetROMFilesystemRootPKc(const char*);
extern "C" void DispatchVariadicArgumentsThroughArgumentList(unsigned,unsigned,...);
extern "C" int Overlay_HandleCardReadCommand(NitroVM*,int);
extern "C" int Cartridge_LoadWithObjectOffsetAndCompletion(NitroHandle*,void*,unsigned,unsigned);
extern "C" int func_ov031_0223b614(NitroHandle*,const void*,unsigned,unsigned);
extern "C" char* data_ov031_02290d24;
extern "C" char data_ov031_0224c544[],data_ov031_0224939c[],data_ov031_0224c55c[];
// Original: arm9/ov031 @ 0x0223B324; symbol: func_ov031_0223b324; size: 0x1B0.
extern "C" void Filesystem_InitializeOverlayArchiveHandle() {
 data_ov031_02290d24=(char*)Memory_AllocateZeroedBlock(0xe8,4);
 NitroVM vm;
 NitroVM_Initialize(&vm);
 if(!_Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(&vm,data_ov031_0224c544)) DisableInterruptsAndHaltForever();
 *(unsigned short*)(data_ov031_02290d24+0xe4)=_Z19GenerateLockOwnerIDv();
 void* image=(void*)vm.fileInfo.startOffset;
 unsigned fnt[2];
 unsigned fat[2];
 _Z16NitroVM_ReadSyncP7NitroVMPvi(&vm,fnt,8);
 _Z16NitroVM_ReadSyncP7NitroVMPvi(&vm,fat,8);
 _Z18NitroVM_FinishReadP7NitroVM(&vm);
 NitroHandle_Initialize((NitroHandle*)(data_ov031_02290d24+0x88));
 if(!NitroHandle_AddToHandleList((NitroHandle*)(data_ov031_02290d24+0x88),data_ov031_0224939c,3)) DisableInterruptsAndHaltForever();
 NitroHandle_SetOpcodeOverride((NitroHandle*)(data_ov031_02290d24+0x88),Overlay_HandleCardReadCommand,0x602);
 if(!NitroHandle_Populate((NitroHandle*)(data_ov031_02290d24+0x88),image,fat[0],fat[1],fnt[0],fnt[1],Cartridge_LoadWithObjectOffsetAndCompletion,func_ov031_0223b614)) DisableInterruptsAndHaltForever();
 unsigned size=NitroHandle_LoadFileTables((NitroHandle*)(data_ov031_02290d24+0x88),0,0);
 *(void**)data_ov031_02290d24=Memory_AllocateZeroedBlock(size,4);
 NitroHandle_LoadFileTables((NitroHandle*)(data_ov031_02290d24+0x88),*(void**)data_ov031_02290d24,size);
 *(void**)(data_ov031_02290d24+0x84)=InitializeSteppedOverlayValues(32,data_ov031_02290d24+4,4);
 char root[128];
 DispatchVariadicArgumentsThroughArgumentList((unsigned)root,(unsigned)data_ov031_0224c55c,data_ov031_0224939c);
 _Z20SetROMFilesystemRootPKc(root);
}
