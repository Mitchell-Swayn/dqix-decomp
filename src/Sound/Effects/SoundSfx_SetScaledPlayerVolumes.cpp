#include <globaldefs.h>
// Original data: arm9/main @ 0x20e7dd4; symbol: data_020e7dd4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000683c13ead562b3f67b3593f0000803f.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float SoundSfxSetScaledPlayerVolumes_UnknownRoleInitializedBytes[];extern "C" void Sound_SetPlayerVolume(int,int);
// Original: arm9/main @ 0x0205E944; symbol: func_0205e944; size: 0xB0.
extern "C" ARM void SoundSfx_SetScaledPlayerVolumes(unsigned char* p,int value){*(int*)(p+200)=value;int scaled=(int)(value*SoundSfxSetScaledPlayerVolumes_UnknownRoleInitializedBytes[p[204]-1]);Sound_SetPlayerVolume(10,scaled);Sound_SetPlayerVolume(11,scaled);Sound_SetPlayerVolume(12,scaled);Sound_SetPlayerVolume(13,scaled);Sound_SetPlayerVolume(14,scaled);Sound_SetPlayerVolume(15,scaled);Sound_SetPlayerVolume(10,scaled);Sound_SetPlayerVolume(12,scaled);Sound_SetPlayerVolume(13,scaled);Sound_SetPlayerVolume(16,scaled);}
