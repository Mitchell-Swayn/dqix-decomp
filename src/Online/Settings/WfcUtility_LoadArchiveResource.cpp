#include "globaldefs.h"
#include "std_library_functions.h"
// Original: arm9/ov031 @ 0x0223b61c; symbol: ReadFileAndOptionallyDecompressIntoSharedAllocation.
// Original data: arm9/ov031 @ 0x224c56c; symbol: data_ov031_0224c56c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2e6c0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290d24; symbol: data_ov031_02290d24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage;extern unsigned char WfcUtilityLoadArchiveResource_UnknownRoleInitializedBytes[];extern "C" void WfcUtility_PopPointerRingBack(unsigned),_Z18NitroVM_InitializeP7NitroVM(void*),DisableInterruptsAndHaltForever(),_Z18NitroVM_FinishReadP7NitroVM(void*),MI_UncompressLZ8(void*,void*),WfcUtility_FreeAllocationAndClearPointer(void**);extern "C" int _Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(void*,const char*),Util_HasMatchingStringSuffix(const char*,const char*,unsigned);extern "C" void* Memory_AllocateZeroedBlock(unsigned,int);extern "C" int _Z16NitroVM_ReadSyncP7NitroVMPvi(void*,void*,int);
extern "C" ARM void* WfcUtility_LoadArchiveResource(const char *path,unsigned *sizeOut,int alignment){WfcUtility_PopPointerRingBack(*(unsigned*)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage+0x84));unsigned vm[18];_Z18NitroVM_InitializeP7NitroVM(vm);if(!_Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(vm,path))DisableInterruptsAndHaltForever();unsigned length=vm[10]-vm[9];if(sizeOut)*sizeOut=length;int selected=Util_HasMatchingStringSuffix(path,(char*)WfcUtilityLoadArchiveResource_UnknownRoleInitializedBytes,2)?-4:alignment;void *buffer=Memory_AllocateZeroedBlock(length,selected);_Z16NitroVM_ReadSyncP7NitroVMPvi(vm,buffer,length);_Z18NitroVM_FinishReadP7NitroVM(vm);if(selected>0)return buffer;unsigned expanded=*(unsigned*)buffer>>8;if(sizeOut)*sizeOut=expanded;void* result=Memory_AllocateZeroedBlock(expanded,alignment);MI_UncompressLZ8(buffer,result);WfcUtility_FreeAllocationAndClearPointer(&buffer);return result;}