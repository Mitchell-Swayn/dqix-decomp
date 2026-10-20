#include "World/WorldPlacementSource.h"

// Original data: arm9/main @ 0x2108fe4; symbol: data_02108fe4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" WorldPlacementSource WorldPlacementSourceInitializeSingleton_UnknownRoleZeroInitializedStorage;

// Original: arm9/main @ 0x0208E0A8; symbol: _ZN20WorldPlacementSource11GetInstanceEv; size: 0xC.
WorldPlacementSource* WorldPlacementSource::GetInstance()
{
    return &WorldPlacementSourceInitializeSingleton_UnknownRoleZeroInitializedStorage;
}
