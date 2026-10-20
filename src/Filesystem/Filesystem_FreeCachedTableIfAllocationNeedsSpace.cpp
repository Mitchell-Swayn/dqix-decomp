#include <globaldefs.h>
#include <Memory/AllocatorUnion.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/LowNitroHandle.h>
// Original data: arm9/main @ 0x2109d90; symbol: data_02109d90.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;extern "C" void* FileCacheRestoreRomTablesIfSpaceAvailable_UnknownRoleZeroInitializedStorage;extern "C" char Filesystem_FreeCachedTableIfAllocationNeedsSpace_TextRom[];extern "C" unsigned Memory_ReadMaximumAlignedAllocation(AllocatorUnion*);extern "C" void Memory_FreeThroughAllocatorUnion(AllocatorUnion*,void*);
// Original: arm9/main @ 0x020A0CC4; symbol: func_020a0cc4; size: 0x94.
extern "C" ARM int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned size){if(((int)size<0||Memory_ReadMaximumAlignedAllocation(&Main_UnknownRoleZeroInitializedStorage_Variant3)<size)&&FileCacheRestoreRomTablesIfSpaceAvailable_UnknownRoleZeroInitializedStorage){BackgroundLoader* loader=BackgroundLoader::GetInstance();if(loader)loader->PauseQueueAndWaitForInFlightWork();NitroHandle*handle=NitroHandle_FindBySignature(Filesystem_FreeCachedTableIfAllocationNeedsSpace_TextRom,3);NitroHandle_ReleaseFileTables(handle);Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,FileCacheRestoreRomTablesIfSpaceAvailable_UnknownRoleZeroInitializedStorage);FileCacheRestoreRomTablesIfSpaceAvailable_UnknownRoleZeroInitializedStorage=0;if(loader)loader->RemoveLock();return 1;}return 0;}
