#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20edf2c; symbol: data_020edf2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101 ...; full span in module reference.
// Observed span: 724 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char SoundVolumeEncodeClampedDecibelAttenuation_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020D2AC4; symbol: func_020d2ac4; size: 0x70.
extern "C" unsigned short SoundVolume_EncodeClampedDecibelAttenuation(int value){if(value<-723)value=-723;else if(value>0)value=0;unsigned v=SoundVolumeEncodeClampedDecibelAttenuation_UnknownRoleInitializedBytes[value+723];unsigned high;if(value<-240)high=3;else if(value<-120)high=2;else if(value<-60)high=1;else high=0;return v|(high<<8);}
