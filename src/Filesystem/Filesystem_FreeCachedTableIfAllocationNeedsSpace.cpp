#include <globaldefs.h>
#include <Memory/AllocatorUnion.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/LowNitroHandle.h>
extern "C" AllocatorUnion data_02114e20;extern "C" void* data_02109d90;extern "C" char data_020f18e8[];extern "C" unsigned Memory_ReadMaximumAlignedAllocation(AllocatorUnion*);extern "C" void Memory_FreeThroughAllocatorUnion(AllocatorUnion*,void*);
// Original: arm9/main @ 0x020A0CC4; symbol: func_020a0cc4; size: 0x94.
extern "C" ARM int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned size){if(((int)size<0||Memory_ReadMaximumAlignedAllocation(&data_02114e20)<size)&&data_02109d90){BackgroundLoader* loader=BackgroundLoader::GetInstance();if(loader)loader->MaybeWaitIdle();NitroHandle*handle=NitroHandle_FindBySignature(data_020f18e8,3);NitroHandle_ReleaseFileTables(handle);Memory_FreeThroughAllocatorUnion(&data_02114e20,data_02109d90);data_02109d90=0;if(loader)loader->RemoveLock();return 1;}return 0;}
