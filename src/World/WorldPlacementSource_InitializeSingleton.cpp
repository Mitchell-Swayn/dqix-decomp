#include <World/WorldPlacementSource.h>
// Original data: arm9/main @ 0x2108fe4; symbol: data_02108fe4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" WorldPlacementSource WorldPlacementSourceInitializeSingleton_UnknownRoleZeroInitializedStorage;
extern "C" WorldPlacementSource *_ZN20WorldPlacementSourceC1Ev(WorldPlacementSource *);
// Original: arm9/main @ 0x020E62A0; symbol: __sinit_020e62a0; size: 0x14.
// Initializes the placement-source singleton by calling its existing constructor.
#pragma define_section init ".init" RX
extern "C" __declspec(section "init") void WorldPlacementSource_InitializeSingleton() { _ZN20WorldPlacementSourceC1Ev(&WorldPlacementSourceInitializeSingleton_UnknownRoleZeroInitializedStorage); }
