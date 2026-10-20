#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char BackgroundLoader_LoadFileAndPassToResourceInitializer_PathDataPrmMonBtldataNat[];extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];extern "C" void MonsterBattleData_CopyFileToAllocatedTable(unsigned,unsigned,void*,unsigned);
// Original: arm9/main @ 0x020709EC; symbol: func_020709ec; size: 0x44.
extern "C" ARM void BackgroundLoader_LoadFileAndPassToResourceInitializer(unsigned a,unsigned b){unsigned size;BackgroundLoader::AddLockGlobal();void* p=LoadFileIntoMemory(BackgroundLoader_LoadFileAndPassToResourceInitializer_PathDataPrmMonBtldataNat,Main_UnknownRoleZeroInitializedStorage_Variant6,&size);MonsterBattleData_CopyFileToAllocatedTable(a,b,p,size);BackgroundLoader::RemoveLockGlobal();}
