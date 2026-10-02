/* Convert envelope fall rates and reset envelope/modulation state for a start. */
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
unsigned short ARM7_ConvertEnvelopeFallRate(int value)
{
 if(value==127)return 65535;
 if(value==126)return 0x3c00;
 if(value<50)return value*2+1;
 return 0x1e00/(126-value);
}
void ARM7_StartSoundVoice(SoundVoice *voice,int argument)
{
 voice->attenuation=-92544;
 voice->envelopeState=0;
 voice->startArgument=argument;
 voice->modulationTime=0;
 voice->modulationCounter=0;
 voice->pendingStart=1;
 voice->active=1;
}
