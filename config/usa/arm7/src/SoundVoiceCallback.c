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
void ARM7_ClearSoundVoiceCallback(SoundVoice *voice)
{
 if(voice){voice->callback=0;voice->userData=0;}
}
