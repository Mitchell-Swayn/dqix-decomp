#include <globaldefs.h>
#include <System/Interrupts.h>
// Original data: arm9/main @ 0x2112148; symbol: data_02112148.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int CartridgeIsExistingCartridge_UnknownRoleZeroInitializedStorage; extern "C" int Cartridge_IsPresentWithoutValidGbaHeader(); extern "C" void OS_SetDPermissionsForProtectionRegion(unsigned,unsigned);
// Original: arm9/main @ 0x020D15B4; symbol: func_020d15b4; size: 0x48.
extern "C" void WriteEnableAndConditionalInterruptMask(int enable) { int state=DisableIRQInterrupts(); CartridgeIsExistingCartridge_UnknownRoleZeroInitializedStorage=enable; if(!Cartridge_IsPresentWithoutValidGbaHeader())OS_SetDPermissionsForProtectionRegion(0xf000,enable?0x1000:0x5000); SetIRQInterruptState(state); }
