/* Stop eligible voices and reserve selected channel masks. */
#pragma dont_inline on
#include "SoundVoice.h"
extern struct { unsigned int mask0,mask1; } ARM7_SoundChannelReservations;
extern SoundVoice ARM7_SoundVoices[16];
extern void ARM7_StopSoundChannel(int,unsigned int);
extern void ARM7_ClearSoundVoiceCallback(SoundVoice*);
void ARM7_StopSoundVoices(unsigned int mask)
{
 SoundVoice *voice; int channel=0;
 while(channel<16 && mask){
  if(mask&1){
   voice=&ARM7_SoundVoices[channel];
   if(!(ARM7_SoundChannelReservations.mask1&(1<<channel))){
    if(voice->callback)voice->callback(voice,0,voice->userData);
    ARM7_StopSoundChannel(channel,0);
    voice->priority=0;
    ARM7_ClearSoundVoiceCallback(voice);
    voice->updates=0;
    voice->active=0;
   }
  }
  channel++;mask>>=1;
 }
}
void ARM7_ReserveSoundChannels(unsigned int mask,unsigned int flags)
{
 SoundVoice *voice; unsigned int remaining; int channel=0; remaining=mask;
 while(channel<16 && remaining){
  if(remaining&1){
   voice=&ARM7_SoundVoices[channel];
   if(!(ARM7_SoundChannelReservations.mask1&(1<<channel))){
    if(voice->callback)voice->callback(voice,0,voice->userData);
    ARM7_StopSoundChannel(channel,0);
    voice->priority=0;
    ARM7_ClearSoundVoiceCallback(voice);
    voice->updates=0;
    voice->active=0;
   }
  }
  channel++;remaining>>=1;
 }
 if(flags&1)ARM7_SoundChannelReservations.mask0|=mask;
 else ARM7_SoundChannelReservations.mask1|=mask;
}
