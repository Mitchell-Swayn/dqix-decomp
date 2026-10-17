#include <globaldefs.h>
#include <System/Mutex.h>
#include <Filesystem/OverlayFSManagement.h>

// The loader writes the first byte of each four-byte flag reservation.
// The remaining bytes preserve each flag's original aligned storage extent.
struct SceneOverlayFlagStorage {
    signed char value;
    unsigned char reserved[3];
};
SceneOverlayFlagStorage data_01ffd340;
SceneOverlayFlagStorage data_01ffd344;
int data_01ffd348; // Current overlay-slot bank.
Mutex data_01ffd34c;
signed char data_01ffd364[8][6]; // Eight banks of six overlay slots.
OverlayMetadata data_01ffd394[35];

typedef char MutexExtentCheck[sizeof(Mutex)==24 ? 1 : -1];
typedef char OverlayMetadataExtentCheck[sizeof(OverlayMetadata)==44 ? 1 : -1];
