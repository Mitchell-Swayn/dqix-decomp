#include "Filesystem/FSInnerDefs.h"

#if defined(usa)
typedef char NitroCartridgeStateSizeCheck[sizeof(Struct_0211173c) == 24 ? 1 : -1];
typedef char NitroHandleSizeCheck[sizeof(NitroHandle) == 92 ? 1 : -1];

// Startup initializes these zero-backed objects before mounting the cartridge.
int data_02111738;
Struct_0211173c data_0211173c;
NitroHandle data_02111754;
#endif
