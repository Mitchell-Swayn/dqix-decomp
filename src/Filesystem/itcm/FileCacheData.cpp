#include "Filesystem/NitroVM.h"
#include "Filesystem/FileCacheState.h"

#if defined(usa)
// CacheMainFileAccessors stores one CRC and one NitroFS handle/file-ID pair
// for each of the 61 configured paths. All entries and the ready flag start zero.
FileCacheReadyFlag CacheMainFileAccessors_UnknownRoleZeroInitializedStorage;
unsigned int CacheMainFileAccessors_UnknownRoleZeroInitializedStorage_Variant2[61];
NitroFileAccessor CacheMainFileAccessors_UnknownRoleZeroInitializedStorage_Variant3[61];
#endif
