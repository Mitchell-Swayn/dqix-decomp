/* Stage PCM metadata or PSG/noise parameters, respecting the hardware
 * channel eligibility ranges, then call the external voice-start routine. */
#pragma dont_inline on
typedef struct { unsigned char format,repeat; unsigned short unknown2,basePeriod,loopStart; unsigned int length; } Waveform;
typedef struct SoundVoice SoundVoice;
struct SoundVoice {
 unsigned char channel,type,envelopeState;
 unsigned char active:1,pendingStart:1,advance:1,updates:5;
 unsigned char unknown4[0x1f];
 unsigned char pan;
 unsigned short volume,period;
 unsigned char unknown28[0x10];
 Waveform waveform;
 unsigned int source;
 void (*callback)(SoundVoice*,int,void*);
 void *userData;
 SoundVoice *next;
};
typedef char VoiceSizeCheck[sizeof(SoundVoice)==0x54?1:-1];
extern void ARM7_StartSoundVoice(SoundVoice*,int);
int ARM7_SetSoundVoicePCM(SoundVoice *voice,const Waveform *waveform,unsigned int source,int argument)
{
 voice->type=0;
 voice->waveform=*waveform;
 voice->source=source;
 ARM7_StartSoundVoice(voice,argument);
 return 1;
}
int ARM7_SetSoundVoicePSG(SoundVoice *voice,unsigned int duty,int argument)
{
 if(voice->channel<8)return 0;
 if(voice->channel>13)return 0;
 voice->type=1;
 voice->source=duty;
 voice->waveform.basePeriod=8006;
 ARM7_StartSoundVoice(voice,argument);
 return 1;
}
int ARM7_SetSoundVoiceNoise(SoundVoice *voice,int argument)
{
 if(voice->channel<14)return 0;
 if(voice->channel>15)return 0;
 voice->type=2;
 voice->waveform.basePeriod=8006;
 ARM7_StartSoundVoice(voice,argument);
 return 1;
}
