#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma opt_propagation off
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[],CharacterViewer_ReloadDollModelParts_PathDataPackLv5CharaPdGp2[],Resource_ReloadObjectGroupAnimationFromGPC_FormatSNsbca[],Resource_ReloadObjectGroupAnimationFromGPC_FormatSBcfg[],Resource_ReloadObjectGroupAnimationFromGPC_TextStand[];
extern "C" int sprintf(char*,const char*,...);
extern "C" void __clear(void*,unsigned);
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void _ZN8Object3D34LoadType0AnimationFromFileInMemoryEiP13SafeAllocatorPKvj(void*,int,void*,const void*,unsigned);
extern "C" void _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj(void*,void*,const void*,unsigned);
extern "C" void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
extern "C" void _ZN8Object3D20StopCurrentAnimationEv(void*);
extern "C" void _ZN8Object3D26RemoveAllAnimationPackagesEv(void*);
extern "C" void* GPC_InitializeReadPairPointerAndMachine(void*);
extern "C" void _Z21ZeroDestroyGPCPointerPP7GPCFile(void*);
extern "C" bool _Z42LoadAndDecompressGPCHeaderAndInnerFileInfoPP7GPCFileR15ExtendedNitroVMPKcPvRjjbPb(void*,void*,const char*,void*,unsigned&,unsigned,bool,bool*);
extern "C" bool _Z27DecompressFileFromGPCByNameRKP7GPCFileR15ExtendedNitroVMPvRjjPKc(void*,void*,void*,unsigned*,unsigned,const char*);
extern "C" void _ZN11GPCReadPair5ResetEv(void*);
extern "C" void Resource_FormatCharacterViewerResourceName(void*,char*,int);
// Original: arm9/ov015 @ 0x0218C920; symbol: func_ov015_0218c920; size: 0x20C.
extern "C" void Resource_ReloadObjectGroupAnimationFromGPC(char* self) {
 unsigned pair[20]; char name[128]; char path[128]; unsigned allocator[5]; unsigned length;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(allocator);
 _ZN13SafeAllocator11CreateTypeAEPvj(allocator,*(void**)(self+0x14),*(unsigned*)(self+0x18));
 _ZN13SafeAllocator5ResetEv(allocator);
 _ZN16BackgroundLoader13AddLockGlobalEv(); _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
 length=0;
 char* buffer=Main_UnknownRoleZeroInitializedStorage_Variant6; unsigned remaining=0x30000;
 GPC_InitializeReadPairPointerAndMachine(pair);
 if(_Z42LoadAndDecompressGPCHeaderAndInnerFileInfoPP7GPCFileR15ExtendedNitroVMPKcPvRjjbPb(pair,pair+1,CharacterViewer_ReloadDollModelParts_PathDataPackLv5CharaPdGp2,buffer,length,remaining,false,0)) {
  buffer+=length; remaining-=length;
  _ZN8Object3D26RemoveAllAnimationPackagesEv(*(char**)(self+0x24));
  _ZN8Object3D26RemoveAllAnimationPackagesEv(*(char**)(self+0x24)+0x158);
  _ZN8Object3D26RemoveAllAnimationPackagesEv(*(char**)(self+0x24)+0x204);
  _ZN8Object3D26RemoveAllAnimationPackagesEv(*(char**)(self+0x24)+0x4b4);
  _ZN8Object3D26RemoveAllAnimationPackagesEv(*(char**)(self+0x24)+0x560);
  _ZN8Object3D26RemoveAllAnimationPackagesEv(*(char**)(self+0x24)+0x60c);
  _ZN8Object3D26RemoveAllAnimationPackagesEv(*(char**)(self+0x24)+0x408);
  _ZN8Object3D26RemoveAllAnimationPackagesEv(*(char**)(self+0x24)+0x35c);
  _ZN8Object3D26RemoveAllAnimationPackagesEv(*(char**)(self+0x24)+0xac);
  __clear(name,0x80); __clear(path,0x80);
  Resource_FormatCharacterViewerResourceName(self,name,0);
  sprintf(path,Resource_ReloadObjectGroupAnimationFromGPC_FormatSNsbca,name);
  _Z27DecompressFileFromGPCByNameRKP7GPCFileR15ExtendedNitroVMPvRjjPKc(pair,pair+1,buffer,&length,remaining,path);
  _ZN8Object3D34LoadType0AnimationFromFileInMemoryEiP13SafeAllocatorPKvj(*(char**)(self+0x24),0,allocator,buffer,length);
  unsigned used=length;
  remaining-=used; sprintf(path,Resource_ReloadObjectGroupAnimationFromGPC_FormatSBcfg,name);
  _Z27DecompressFileFromGPCByNameRKP7GPCFileR15ExtendedNitroVMPvRjjPKc(pair,pair+1,buffer+used,&length,remaining,path);
  _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj(*(char**)(self+0x24),allocator,buffer+used,length);
  _ZN13SafeAllocator7DestroyEv(allocator);
  _ZN8Object3D20StopCurrentAnimationEv(*(char**)(self+0x24));
  _ZN8Object3D18SetAnimationByNameEPKci(*(char**)(self+0x24),Resource_ReloadObjectGroupAnimationFromGPC_TextStand,0);
 }
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
 _ZN11GPCReadPair5ResetEv(pair);
 _Z21ZeroDestroyGPCPointerPP7GPCFile(pair);
}
