#pragma thumb off
// Original: arm9/main @ 0x02012534; symbol: func_02012534; size: 0x4.
// __sinit_020e66a0 registers this callback for the global touch-input state
// at 0x02114E54 through __register_global_object. Its state needs no cleanup.
extern "C" void TouchInput_DestroyGlobalState(void* touchInput, int destructorFlags) {}
