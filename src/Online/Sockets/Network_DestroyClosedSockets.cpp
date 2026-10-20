#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x224e230; symbol: data_ov031_0224e230.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkDestroyClosedSockets_UnknownRoleZeroInitializedStorage[];
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void Network_DestroySocketStorage();
// Original: arm9/ov031 @ 0x02206C08; symbol: func_ov031_02206c08; size: 0x3C.
extern "C" void Network_DestroyClosedSockets(void) {
    int irq = _Z20DisableIRQInterruptsv();
    if (*(unsigned *)NetworkDestroyClosedSockets_UnknownRoleZeroInitializedStorage) {
        do { Network_DestroySocketStorage(); }
        while (*(unsigned *)NetworkDestroyClosedSockets_UnknownRoleZeroInitializedStorage);
    }
    _Z20SetIRQInterruptStatei(irq);
}
