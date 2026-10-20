#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x20fdd44; symbol: data_020fdd44.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 3168 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
unsigned short *Zone3D_GetMainInstance();extern char ZoneStateGetTrackedZoneCache_UnknownRoleZeroInitializedStorage[];void ZoneState_FindTrackedZoneByIdentifier(void *,int);
// Original: arm9/main @ 0x02027CB0; symbol: func_02027cb0; size: 0x1C.
void ZoneState_FindCurrentTrackedZone(){ZoneState_FindTrackedZoneByIdentifier(ZoneStateGetTrackedZoneCache_UnknownRoleZeroInitializedStorage,*Zone3D_GetMainInstance());}
}
