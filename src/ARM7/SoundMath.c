/* Sound utilities: clamp attenuation, select hardware volume divisor,
 * mirror the quarter-wave sine table, and advance an unsigned 32-bit LCG. */
#pragma dont_inline on
extern unsigned int ARM7_BiosVolumeTable(unsigned int);
extern const signed char ARM7_SoundSineTable[33];
extern unsigned int ARM7_SoundRandomState;
unsigned int ARM7_GetSoundVolumeTable(unsigned int);
unsigned short ARM7_ConvertSoundAttenuation(int attenuation)
{
 int divisor;
 unsigned int volume;
 if(attenuation<-723)attenuation=-723;
 else if(attenuation>0)attenuation=0;
 volume=ARM7_GetSoundVolumeTable(attenuation+723);
 if(attenuation<-240)divisor=3;
 else if(attenuation<-120)divisor=2;
 else if(attenuation<-60)divisor=1;
 else divisor=0;
 return volume|(divisor<<8);
}
unsigned int ARM7_GetSoundVolumeTable(unsigned int index)
{
 return ARM7_BiosVolumeTable(index);
}
signed char ARM7_GetSoundSine(int phase)
{
 if(phase<32)return ARM7_SoundSineTable[phase];
 if(phase<64)return ARM7_SoundSineTable[64-phase];
 if(phase<96)return -ARM7_SoundSineTable[phase-64];
 return -ARM7_SoundSineTable[32-(phase-96)];
}
unsigned short ARM7_NextSoundRandom(void)
{
 ARM7_SoundRandomState=ARM7_SoundRandomState*1664525+1013904223;
 return ARM7_SoundRandomState>>16;
}
