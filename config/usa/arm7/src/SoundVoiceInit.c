/* Initialize channel IDs, clear pending-update and active bits, and reset
 * list endpoints. Unidentified state bytes retain explicit offset names. */
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
SoundVoice ARM7_SoundVoices[16];
extern struct { SoundVoice *first,*last; } ARM7_SoundVoiceList;
void ARM7_InitializeSoundChannels(void)
{
 int channel=0;
 do{
  ARM7_SoundVoices[channel].channel=channel;
  ARM7_SoundVoices[channel].updates=0;
  ARM7_SoundVoices[channel].active=0;
  channel++;
 }while(channel<16);
 ARM7_SoundVoiceList.first=ARM7_SoundVoiceList.last=0;
}
