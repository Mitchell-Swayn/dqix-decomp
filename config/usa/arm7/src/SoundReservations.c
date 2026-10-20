/* Sound voice callback cleanup and channel reservation/range controls. */
#pragma dont_inline on
#include "SoundVoice.h"
extern struct { unsigned int mask0,mask1; } ARM7_SoundChannelReservations;
extern SoundVoice ARM7_SoundVoices[16];
extern void ARM7_StopSoundChannel(int,unsigned int);
// Original: arm7/wram @ 0x03800378; symbol: ARM7_ReleaseSoundChannelReservations.
void ARM7_ReleaseSoundChannelReservations(unsigned int mask,unsigned int flags)
{
 if(flags&1)ARM7_SoundChannelReservations.mask0&=~mask; else ARM7_SoundChannelReservations.mask1&=~mask;
}
// Original: arm7/wram @ 0x038003B0; symbol: ARM7_GetSoundChannelReservations.
unsigned int ARM7_GetSoundChannelReservations(unsigned int flags)
{
 if(flags&1)return ARM7_SoundChannelReservations.mask0;
 return ARM7_SoundChannelReservations.mask1;
}
// Original: arm7/wram @ 0x038003CC; symbol: ARM7_StopSoundVoicesInRange.
void ARM7_StopSoundVoicesInRange(unsigned int start,unsigned int end)
{
 unsigned char channel=0;
 do{
  SoundVoice *voice=&ARM7_SoundVoices[channel];
  if(voice->active && voice->type==0 && start<=voice->source && voice->source<=end){
   voice->pendingStart=0;
   ARM7_StopSoundChannel(channel,0);
  }
  channel++;
 }while(channel<16);
}
