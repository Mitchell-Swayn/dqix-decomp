/* Configure PCM, PSG and noise channel registers while retaining requested
 * pan/volume separately from software overrides. An explicit byte offset
 * preserves the channel address across the optional volume-adjustment call. */
#pragma dont_inline on
extern int ARM7_SoundPanOverride;
extern int ARM7_SoundVolumeAdjustment;
extern unsigned char ARM7_RequestedSoundPan[16];
extern unsigned char ARM7_RequestedSoundVolume[16];
extern int ARM7_AdjustSoundVolume(int,int);
#define CONTROL(n) (*(volatile unsigned int*)(0x04000400+(n)))
#define SOURCE(n) (*(volatile unsigned int*)(0x04000404+(n)))
#define TIMER(n) (*(volatile unsigned short*)(0x04000408+(n)))
#define LOOP(n) (*(volatile unsigned short*)(0x0400040a+(n)))
#define LENGTH(n) (*(volatile unsigned int*)(0x0400040c+(n)))
void ARM7_ConfigurePCMChannel(int channel,unsigned int source,int format,int repeat,int loopStart,int length,int volume,int divisor,int period,int pan)
{
 unsigned int offset=channel*16;
 ARM7_RequestedSoundPan[channel]=pan;
 if(ARM7_SoundPanOverride>=0)pan=ARM7_SoundPanOverride;
 ARM7_RequestedSoundVolume[channel]=volume;
 if(ARM7_SoundVolumeAdjustment>0 && (0xfff5 & (1<<channel)))volume=ARM7_AdjustSoundVolume(volume,pan);
 CONTROL(offset)=(format<<29)|(repeat<<27)|(pan<<16)|(divisor<<8)|volume;
 TIMER(offset)=0x10000-period;
 LOOP(offset)=loopStart;
 LENGTH(offset)=length;
 SOURCE(offset)=source;
}
void ARM7_ConfigurePSGChannel(int channel,int duty,int volume,int divisor,int period,int pan)
{
 unsigned int offset=channel*16;
 ARM7_RequestedSoundPan[channel]=pan;
 if(ARM7_SoundPanOverride>=0)pan=ARM7_SoundPanOverride;
 ARM7_RequestedSoundVolume[channel]=volume;
 if(ARM7_SoundVolumeAdjustment>0 && (0xfff5 & (1<<channel)))volume=ARM7_AdjustSoundVolume(volume,pan);
 CONTROL(offset)=(duty<<24)|0x60000000|(pan<<16)|(divisor<<8)|volume;
 TIMER(offset)=0x10000-period;
}
void ARM7_ConfigureNoiseChannel(int channel,int volume,int divisor,int period,int pan)
{
 unsigned int offset=channel*16;
 ARM7_RequestedSoundPan[channel]=pan;
 if(ARM7_SoundPanOverride>=0)pan=ARM7_SoundPanOverride;
 ARM7_RequestedSoundVolume[channel]=volume;
 if(ARM7_SoundVolumeAdjustment>0 && (0xfff5 & (1<<channel)))volume=ARM7_AdjustSoundVolume(volume,pan);
 CONTROL(offset)=(pan<<16)|0x60000000|(divisor<<8)|volume;
 TIMER(offset)=0x10000-period;
}
