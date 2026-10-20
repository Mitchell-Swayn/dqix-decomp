#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <World/Zone3DEmbeddedState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
// Original data: arm9/main @ 0x20f2a30; symbol: data_020f2a30.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 612a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2a38; symbol: data_020f2a38.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex c82a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];extern "C" const char* CharacterViewerRun_UnknownRoleDataReferences_Variant2;extern "C" const char* CharacterViewerRun_UnknownRoleDataReferences;extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
struct Object{SafeAllocator allocator;ZoneState2754 state;ZoneState2754* current;};
// Original: arm9/main @ 0x0207D6DC; symbol: func_0207d6dc; size: 0xB0.
extern "C" ARM void AllocatePerCountBufferAndBuildGP2State(Object* p,const short* keys,int count){unsigned bytes=count<<8;void* buffer=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,bytes);p->allocator.CreateTypeA(buffer,bytes);p->allocator.Reset();p->state.Reset();BackgroundLoader::AddLockGlobal();unsigned size=0;void* file=Filesystem_ExtractLocalizedGp2FileToScratch(CharacterViewerRun_UnknownRoleDataReferences_Variant2,CharacterViewerRun_UnknownRoleDataReferences,&size);if(file)p->state.BuildForKeys(&p->allocator,file,size,keys,(unsigned short)count);BackgroundLoader::RemoveLockGlobal();p->current=&p->state;}
