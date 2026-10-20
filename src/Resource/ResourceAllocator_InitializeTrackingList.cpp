#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void _ZN19SignedAllocatorList10InitializeEt(void*,unsigned short);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020BDBE0; symbol: func_020bdbe0; size: 0x10.
extern "C" void ResourceAllocator_InitializeTrackingList(void* a){_ZN19SignedAllocatorList10InitializeEt(a,0);}
