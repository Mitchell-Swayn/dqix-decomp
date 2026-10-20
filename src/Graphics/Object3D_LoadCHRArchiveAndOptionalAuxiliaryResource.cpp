#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <World/Object3D.h>
#include <Resource/ResourceMutex.h>
#include <Filesystem/NarcHandle.h>
#include <Filesystem/LowNitroHandle.h>
#include <Filesystem/FileAccessor.h>
// Original data: arm9/main @ 0x20f04b8; symbol: data_020f04b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2e62656666000000646174612f616e692f25732e4e43455200646174612f616e692f25732e4e414e5200646174612f616e692f25732e4e43475200646174612f ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource_TextARC[],Object3DLoadCHRArchiveAndOptionalAuxiliaryResource_UnknownRoleInitializedBytes[];extern "C" void InitializeSignedAllocatorLists(void*);extern "C" void ResourceTracks_RelocateSectionsAndCreateKeyframeLists(void*,SafeAllocator*,const void*,int);
// Original: arm9/main @ 0x020553EC; symbol: func_020553ec; size: 0x16C.
extern "C" int Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource(unsigned* p,unsigned value,SafeAllocator* allocator,const unsigned char* file,int arg) {p[0]=value;p[0x7a]=0;Object3D* object=(Object3D*)(p+5);object->Initialize();InitializeSignedAllocatorLists(p+0x30);if(allocator)p[1]=(unsigned)allocator;ObjectArchiveLoadInfo info;info.unk_0=0;info.unk_10=0;info.unk_14=0;info.unk_18=0;info.packageID=0;info.fileData=file;info.unk_8=arg;info.allocator=allocator;object->LoadFromCHRArchive(&info);LockResourceMutex();NarcHandle archive;if(archive.Initialize(Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource_TextARC,file)) {NitroVM vm;NitroVM_Initialize(&vm);char path[80];unsigned index=0;while(PrepareReadFileInNARCByID(&vm,&archive,index)) {NitroVM_WriteOutFilePath(&vm,path,80);if(strstr(path,Object3DLoadCHRArchiveAndOptionalAuxiliaryResource_UnknownRoleInitializedBytes)) {const void* data=archive.GetFileByIndex(index);int length=vm.fileInfo.endOffset;length-=vm.fileInfo.startOffset;ResourceTracks_RelocateSectionsAndCreateKeyframeLists(p+0x30,allocator,data,length);p[0x7a]=1;NitroVM_FinishRead(&vm);break;}NitroVM_FinishRead(&vm);++index;}archive.Destroy();}UnlockResourceMutex();if(!p[0x7a])object->SetBCFGAnimationByIndex(0,0);return 1; }
