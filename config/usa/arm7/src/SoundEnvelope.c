/* Advance attack/decay/sustain/release state and expose envelope parameters. */
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
extern const short ARM7_SoundAttenuationTable[128];
extern const unsigned char ARM7_SoundAttackTable[19];
extern unsigned short ARM7_ConvertEnvelopeFallRate(int);
int ARM7_UpdateSoundEnvelope(SoundVoice *voice,int tick)
{
 if(tick){
  switch(voice->envelopeState){
  case 0:
   voice->attenuation=-((-voice->attenuation*voice->attack)>>8);
   if(voice->attenuation==0)voice->envelopeState=1;
   break;
  case 1:{
   int sustain=ARM7_SoundAttenuationTable[voice->sustain]<<7;
   voice->attenuation-=voice->decay;
   if(voice->attenuation<=sustain){voice->attenuation=sustain;voice->envelopeState=2;}
   break;
  }
  case 2:break;
  case 3:voice->attenuation-=voice->release;break;
  }
 }
 return voice->attenuation>>7;
}
void ARM7_SetSoundVoiceAttack(SoundVoice *voice,int attack)
{
 if(attack<109)attack=255-attack; else attack=ARM7_SoundAttackTable[127-attack];
 voice->attack=attack;
}
void ARM7_SetSoundVoiceDecay(SoundVoice *voice,int decay)
{
 voice->decay=ARM7_ConvertEnvelopeFallRate(decay);
}
void ARM7_SetSoundVoiceSustain(SoundVoice *voice,int sustain)
{
 voice->sustain=sustain;
}
void ARM7_SetSoundVoiceRelease(SoundVoice *voice,int release)
{
 voice->release=ARM7_ConvertEnvelopeFallRate(release);
}
void ARM7_BeginSoundVoiceRelease(SoundVoice *voice)
{
 voice->envelopeState=3;
}
int ARM7_IsSoundVoiceActive(SoundVoice *voice)
{
 return voice->active;
}
