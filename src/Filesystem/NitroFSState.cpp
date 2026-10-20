#include "Filesystem/FSInnerDefs.h"

#if defined(usa)
typedef char NitroCartridgeStateSizeCheck[sizeof(Struct_0211173c) == 24 ? 1 : -1];
typedef char NitroHandleSizeCheck[sizeof(NitroHandle) == 92 ? 1 : -1];

// Startup initializes these zero-backed objects before mounting the cartridge.
int InitializeROMFilesystem_UnknownRoleZeroInitializedStorage;
Struct_0211173c ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage;
NitroHandle ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2;
#endif
