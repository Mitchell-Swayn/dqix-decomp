// Retrieve the overlay controller, then reset its pending work.
extern "C" void* ReadWordFieldAtOffset1C();
extern "C" void Object_ResetEmbeddedTextStateAndWord38(void* controller);
// Original: arm9/ov020 @ 0x0218B700; symbol: func_ov020_0218b700; size: 0x10.
extern "C" void func_ov020_0218b700() { Object_ResetEmbeddedTextStateAndWord38(ReadWordFieldAtOffset1C()); }
