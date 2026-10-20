// Original data: arm9/ov031 @ 0x224d9c0; symbol: data_ov031_0224d9c0.
// Networking worker thread stack. func_ov031_02200298 passes top address 0224e1c0 and size 0x800 to OS_CreateThread (func_020c75b4); this extent backs that descending stack.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2048 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Networking worker thread stack. func_ov031_02200298 passes top address 0224e1c0 and size 0x800 to OS_CreateThread (func_020c75b4); this extent backs that descending stack.
extern "C" {
unsigned int NetworkInitializeStackAndStartWorkerThreads_NetworkingWorkerThreadStack[512];
}
