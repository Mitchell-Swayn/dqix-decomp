#include <globaldefs.h>
struct TransitionFlagView { unsigned char low:1; unsigned char half:1; unsigned char high:6; };
// Original data: arm9/main @ 0x20e8ec4; symbol: data_020e8ec4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000683c13ead562b3f67b3593f0000803f.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float BgmSetPlaybackVolumeAndFade_UnknownRoleInitializedBytes[];
extern "C" void NNS_SndPlayerMoveVolume(void*,int,int);
extern "C" void Sound_SetPlayerVolume(int,int);
// Original: arm9/main @ 0x0209C2E0; symbol: func_0209c2e0; size: 0xCC.
extern "C" ARM void Bgm_SetPlaybackVolumeAndFade(unsigned char* self,unsigned char value,int duration) { self[0xcd]=value; float scale=((float)(int)self[0xcc]-1.0f)/4.0f; int amount=(int)((float)(unsigned)self[0xcd]*scale); if(((TransitionFlagView*)(self+0xc8))->half) amount/=2; NNS_SndPlayerMoveVolume(self+0xbc,amount,duration); NNS_SndPlayerMoveVolume(self+0xc0,amount,duration); int channel=(int)((float)(unsigned)self[0xcd]*BgmSetPlaybackVolumeAndFade_UnknownRoleInitializedBytes[self[0xcc]-1]); Sound_SetPlayerVolume(5,channel); Sound_SetPlayerVolume(7,channel); Sound_SetPlayerVolume(6,channel); }
