#include <globaldefs.h>
ARM
struct Descriptor {char pad[0x44];unsigned char low:4,mode:4;unsigned char overrideMode:1,other:7;};
// Original: arm9/ov023 @ 0x021F86B8; symbol: func_ov023_021f86b8; size: 0x24.
// Returns mode five when the override flag is set, otherwise the descriptor's high-nibble mode.
extern "C" unsigned char Graphics_ReadDescriptorModeOrOverride(const Descriptor* self){return self->overrideMode?5:self->mode;}
