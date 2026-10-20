// Original: arm9/main @ 0x020C0158; symbol: func_020c0158; size: 0x4.
// Resource backend close callback: selector installs void (*close)(void *).
// This backend owns no close-time resource; callers ignore the return value.
extern "C" void ResourceBackend_CloseNoOp(void *resourceState) {}
