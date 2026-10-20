#include <globaldefs.h>
#include <System/Mutex.h>
#include <Filesystem/OverlayFSManagement.h>

// The loader writes the first byte of each four-byte flag reservation.
// The remaining bytes preserve each flag's original aligned storage extent.
struct SceneOverlayFlagStorage {
    signed char value;
    unsigned char reserved[3];
};
SceneOverlayFlagStorage OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage;
SceneOverlayFlagStorage OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2;
int IsSceneLoaded_UnknownRoleZeroInitializedStorage; // Current overlay-slot bank.
Mutex OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3;
signed char IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2[8][6]; // Eight banks of six overlay slots.
OverlayMetadata OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant4[35];

typedef char MutexExtentCheck[sizeof(Mutex)==24 ? 1 : -1];
typedef char OverlayMetadataExtentCheck[sizeof(OverlayMetadata)==44 ? 1 : -1];
