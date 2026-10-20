#include <globaldefs.h>
// Original data: arm9/ov017 @ 0x21d82e0; symbol: data_ov017_021d82e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char* FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage[2];
extern "C" void PartyStatus_SetSnapshotTrackingEnabled(void*,unsigned,unsigned);
// Original: arm9/ov017 @ 0x0218B5C0; symbol: func_ov017_0218b5c0; size: 0x38.
extern "C" ARM void GameResources_SetPartyStatusSnapshotTracking(unsigned field,unsigned value) { unsigned char* object=FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage[1]; if(object && *(void**)(object+0x36d0)) PartyStatus_SetSnapshotTrackingEnabled(*(void**)(object+0x36d0),field,value); }
