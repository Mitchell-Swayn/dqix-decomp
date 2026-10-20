#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FC400; symbol: Object_GetEmbeddedAddressAtOffset20_021fc400; size: 0x8.
// Returns the address object+0x20. The embedded member type is unknown; address suffix temporarily distinguishes equivalent offset-0x20 accessors.
extern "C" void* MenuScript_GetExecutionContext(void* self) { return (unsigned char*)self + 0x20; }
