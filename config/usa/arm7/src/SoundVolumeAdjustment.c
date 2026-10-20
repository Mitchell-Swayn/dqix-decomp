/* Volume correction is piecewise linear outside the central pan interval.
 * Factor, requested pan and requested volume share the recovered 36-byte BSS
 * block. Hardware refresh applies to channel mask 0xfff5. */
#pragma dont_inline on
typedef struct { int adjustment; unsigned char requestedPan[16],requestedVolume[16]; } SoundChannelState;
SoundChannelState ARM7_SoundChannelState;
#define ARM7_SoundVolumeAdjustment ARM7_SoundChannelState.adjustment
#define ARM7_RequestedSoundVolume ARM7_SoundChannelState.requestedVolume
int ARM7_AdjustSoundVolume(int,int);
// Original: arm7/wram @ 0x037FF270; symbol: ARM7_SetSoundVolumeAdjustment.
void ARM7_SetSoundVolumeAdjustment(int factor)
{
 int channel=0;
 ARM7_SoundVolumeAdjustment=factor;
 do{
  if(0xfff5 & (1<<channel)){
   unsigned int offset=16*channel;
   int pan=*(volatile unsigned char*)(0x04000402+offset);
   int volume=ARM7_AdjustSoundVolume(ARM7_RequestedSoundVolume[channel],pan);
   *(volatile unsigned char*)(0x04000400+offset)=volume;
  }
  channel++;
 }while(channel<16);
}
// Original: arm7/wram @ 0x037FF2D0; symbol: ARM7_AdjustSoundVolume.
int ARM7_AdjustSoundVolume(int volume,int pan)
{
 if(pan<24)return (volume*(ARM7_SoundVolumeAdjustment*(pan+40)+((32767-ARM7_SoundVolumeAdjustment)<<6)))>>21;
 if(pan>104)return (volume*(-ARM7_SoundVolumeAdjustment*(pan-40)+((32767+ARM7_SoundVolumeAdjustment)<<6)))>>21;
 return volume;
}
