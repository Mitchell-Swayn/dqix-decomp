#include <globaldefs.h>
#include <Memory/AllocatorUnion.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileAccessor.h>
ARM
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" void* FileCacheRestoreRomTablesIfSpaceAvailable_UnknownRoleZeroInitializedStorage;
extern "C" unsigned Memory_ReadMaximumAlignedAllocation(char*);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*, unsigned);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
void CacheMainFileAccessors();
// Original: arm9/main @ 0x020A0C0C; symbol: FileCache_RestoreRomTablesIfSpaceAvailable; size: 0xB8.
// Allocates and loads cached ROM file tables while holding the background loader lock.
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable()
{
    if (FileCacheRestoreRomTablesIfSpaceAvailable_UnknownRoleZeroInitializedStorage) return;
    unsigned tableSize = LoadROMFilesystemFileTables(0, 0);
    unsigned available = Memory_ReadMaximumAlignedAllocation((char*)&Main_UnknownRoleZeroInitializedStorage_Variant3);
    if (tableSize + 16 > available) return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader) loader->AddLock();
    void* temporary = AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3, available - (tableSize + 16));
    FileCacheRestoreRomTablesIfSpaceAvailable_UnknownRoleZeroInitializedStorage = AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3, tableSize);
    Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, temporary);
    if (FileCacheRestoreRomTablesIfSpaceAvailable_UnknownRoleZeroInitializedStorage) LoadROMFilesystemFileTables(FileCacheRestoreRomTablesIfSpaceAvailable_UnknownRoleZeroInitializedStorage, tableSize);
    if (loader) loader->RemoveLock();
    CacheMainFileAccessors();
}
