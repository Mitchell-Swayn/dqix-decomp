#include <Filesystem/FileIO.h>
#include <std_library_functions.h>
#pragma always_inline on
// Original data: arm9/main @ 0x20ee218; symbol: data_020ee218.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000100000002000000030000000400000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee230; symbol: data_020ee230.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 6562303430302e63687200006562303433302e63687200006562303434302e63687200006562303432302e63687200006562303431302e636872000000000000 ...; full span in module reference.
// Observed span: 72 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Names{char bytes[72];};struct Keys{int key[6];};extern "C" Names LoadNamedArchiveEntriesWithTextureVRAMState_UnknownRoleInitializedBytes_Variant2;extern "C" Keys LoadNamedArchiveEntriesWithTextureVRAMState_UnknownRoleInitializedBytes;extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);extern "C" void Object_InvokeSaveTextureImageVRAMState(void*);extern "C" void InitializeOwnerIndicesObjectAndEmbeddedState(void*);extern "C" int Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource(void*,int,SafeAllocator*,void*,unsigned int);
// Original: arm9/main @ 0x020D6D90; symbol: func_020d6d90; size: 0x138.
extern "C" int LoadNamedArchiveEntriesWithTextureVRAMState(unsigned char *self,const void *archive,SafeAllocator *allocator,void *lock){unsigned int length;const void *file;Keys keys;Names names;self[0xa3c]=0;*(int*)(self+0xa20)=0;Graphics_RestoreTextureImageAndPaletteVRAMState(lock);names=LoadNamedArchiveEntriesWithTextureVRAMState_UnknownRoleInitializedBytes_Variant2;keys=LoadNamedArchiveEntriesWithTextureVRAMState_UnknownRoleInitializedBytes;char *name=names.bytes;int *key=keys.key;unsigned char *last=0;for(;*name;name+=12,++key){if(GetFileInNarc(archive,name,&file,&length,0)){unsigned char *object=(unsigned char*)allocator->Allocate(0x1f0);void *copy=allocator->Allocate(length);if(object&&copy){memcpy(copy,file,length);InitializeOwnerIndicesObjectAndEmbeddedState(object);if(Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource(object,*key,allocator,copy,length)){if(last)*(unsigned char**)(last+0x1ec)=object;else *(unsigned char**)(self+0xa20)=object;last=object;}}}}Object_InvokeSaveTextureImageVRAMState(lock);return 1;}
