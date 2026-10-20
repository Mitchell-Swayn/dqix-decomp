#include <globaldefs.h>
ARM
#pragma define_section init ".init" RX
struct DestructorNode { DestructorNode* next; void* (*destroy)(void*, int); void* object; };
extern "C" {
// Original data: arm9/main @ 0x20fefec; symbol: data_020fefec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2100044; symbol: data_02100044.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2507 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char NetworkGetConnectionManager_UnknownRoleZeroInitializedStorage[], NetworkGetCommandRecordPool_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20fefd4; symbol: data_020fefd4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20fefe0; symbol: data_020fefe0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern DestructorNode Sinit020E5B28_UnknownRoleZeroInitializedStorage_Variant2, Sinit020E5B28_UnknownRoleZeroInitializedStorage;
void* Network_ConstructConnectionManager(void*); void* Network_ConstructCommandRecordPool(void*);
void* Network_DestroyConnectionManager(void*, int); void* Network_ResetCommandRecordPoolAndListHeaders(void*, int);
void __register_global_object(void*, void* (*)(void*,int), DestructorNode*);
// Original: arm9/main @ 0x020E5B28; symbol: __sinit_020e5b28; size: 0x50.
__declspec(section "init") void __sinit_020e5b28() {
 Network_ConstructConnectionManager(NetworkGetConnectionManager_UnknownRoleZeroInitializedStorage);
 __register_global_object(NetworkGetConnectionManager_UnknownRoleZeroInitializedStorage, Network_DestroyConnectionManager, &Sinit020E5B28_UnknownRoleZeroInitializedStorage_Variant2);
 Network_ConstructCommandRecordPool(NetworkGetCommandRecordPool_UnknownRoleZeroInitializedStorage);
 __register_global_object(NetworkGetCommandRecordPool_UnknownRoleZeroInitializedStorage, Network_ResetCommandRecordPoolAndListHeaders, &Sinit020E5B28_UnknownRoleZeroInitializedStorage);
}
}
