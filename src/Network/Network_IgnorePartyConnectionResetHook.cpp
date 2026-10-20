#pragma thumb off
// Original: arm9/main @ 0x020D84DC; symbol: func_020d84dc; size: 0x4.
// No arguments/result are used by the observed ov017 caller at 0x021C3660.
// Returns without changing any state; the wider purpose of this hook is unknown.
extern "C" void Network_IgnorePartyConnectionResetHook() {}
