/* Apply pending voice updates in two passes: configure/stop/update all
 * channels first, then enable newly configured channels and clear update bits. */
#pragma dont_inline on
#include "SoundVoice.h"
extern SoundVoice ARM7_SoundVoices[16];
extern void ARM7_StopSoundChannel(int,unsigned int);
extern void ARM7_ConfigurePCMChannel(int,unsigned int,int,int,int,int,int,int,int,int);
extern void ARM7_ConfigurePSGChannel(int,int,int,int,int,int);
extern void ARM7_ConfigureNoiseChannel(int,int,int,int,int);
extern void ARM7_SetSoundChannelPeriod(int,int);
extern void ARM7_SetSoundChannelVolume(int,int,int);
extern void ARM7_SetSoundChannelPan(int,int);
void ARM7_ApplySoundChannelUpdates(void)
{
 SoundVoice *voice;
 int channel=0;
 do{
  voice=&ARM7_SoundVoices[channel];
  if(voice->updates){
   if(voice->updates&2)ARM7_StopSoundChannel(channel,0);
   if(voice->updates&1){
    switch(voice->type){
    case 0:ARM7_ConfigurePCMChannel(channel,voice->source,voice->waveform.format,voice->waveform.repeat?1:2,voice->waveform.loopStart,voice->waveform.length,voice->volume&255,voice->volume>>8,voice->period,voice->pan);break;
    case 1:ARM7_ConfigurePSGChannel(channel,voice->source,voice->volume&255,voice->volume>>8,voice->period,voice->pan);break;
    case 2:ARM7_ConfigureNoiseChannel(channel,voice->volume&255,voice->volume>>8,voice->period,voice->pan);break;
    }
   }else{
    if(voice->updates&4)ARM7_SetSoundChannelPeriod(channel,voice->period);
    if(voice->updates&8)ARM7_SetSoundChannelVolume(channel,voice->volume&255,voice->volume>>8);
    if(voice->updates&16)ARM7_SetSoundChannelPan(channel,voice->pan);
   }
  }
  channel++;
 }while(channel<16);
 {
  int channel=0;
  do{
   SoundVoice *voice=&ARM7_SoundVoices[channel];
   if(voice->updates){
    if(voice->updates&1)*(volatile unsigned char*)(0x04000403+16*channel)|=0x80;
    voice->updates=0;
   }
   channel++;
  }while(channel<16);
 }
}
