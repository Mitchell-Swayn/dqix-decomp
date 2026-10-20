extern "C" void __clear(void*,unsigned);
#include <globaldefs.h>
#include <std_library_functions.h>
// Original data: arm9/main @ 0x20fefec; symbol: data_020fefec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Network_ProcessDiscoveredPeerAdvertisement_TextUnknown[];extern "C" char NetworkGetConnectionManager_UnknownRoleZeroInitializedStorage[];extern "C" void Text_CopyBoundedStringAndReturnSourceLength(void*,const void*,unsigned);extern "C" void Network_RefreshOrAppendMacAddressEntry(void*,void*);struct Owner {char pad[0x3c];unsigned short flag;char pad2[12];unsigned char kind;char pad3[5];char data[20];unsigned char count;};
// Original: arm9/main @ 0x0202AE4C; symbol: func_0202ae4c; size: 0x70.
extern "C" void Network_ProcessDiscoveredPeerAdvertisement(Owner* self) {char buffer[21];__clear(buffer,21);if(self->flag && self->kind==36)memcpy(buffer,self->data,self->count);else Text_CopyBoundedStringAndReturnSourceLength(buffer,Network_ProcessDiscoveredPeerAdvertisement_TextUnknown,21);Network_RefreshOrAppendMacAddressEntry(NetworkGetConnectionManager_UnknownRoleZeroInitializedStorage,self); }
