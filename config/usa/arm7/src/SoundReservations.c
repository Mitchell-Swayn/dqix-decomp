/* Sound voice callback cleanup and channel reservation/range controls. */
#pragma dont_inline on
typedef struct { unsigned char format,repeat; unsigned short unknown2,basePeriod,loopStart; unsigned int length; } Waveform;
typedef struct SoundVoice SoundVoice;
struct SoundVoice {
 unsigned char channel,type,envelopeState;
 unsigned char active:1,pendingStart:1,advance:1,updates:5;
 unsigned char unknown4[12];
 int attenuation,elapsed,duration;
 unsigned char attack,sustain;
 unsigned short decay,release;
 unsigned char priority;
 unsigned char pan;
 unsigned short volume,period;
 unsigned char unknown28[6];
 unsigned short modulationCounter,modulationTime;
 short sweep;
 int startArgument;
 Waveform waveform;
 unsigned int source;
 void (*callback)(SoundVoice*,int,void*);
 void *userData;
 SoundVoice *next;
};
typedef char VoiceSizeCheck[sizeof(SoundVoice)==0x54?1:-1];
extern struct { unsigned int mask0,mask1; } ARM7_SoundChannelReservations;
extern SoundVoice ARM7_SoundVoices[16];
extern void ARM7_StopSoundChannel(int,unsigned int);
void ARM7_ReleaseSoundChannelReservations(unsigned int mask,unsigned int flags)
{
 if(flags&1)ARM7_SoundChannelReservations.mask0&=~mask; else ARM7_SoundChannelReservations.mask1&=~mask;
}
unsigned int ARM7_GetSoundChannelReservations(unsigned int flags)
{
 if(flags&1)return ARM7_SoundChannelReservations.mask0;
 return ARM7_SoundChannelReservations.mask1;
}
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
