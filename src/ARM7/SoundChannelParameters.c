/* Update channel parameters and inspect hardware activity/control. Negative
 * pan override restores each channel requested value; nonnegative override
 * writes the same pan byte to all channels. Software state stays external. */
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
#define PAN(n) (*(volatile unsigned char*)(0x04000402+16*(n)))
#define VOLUME(n) (*(volatile unsigned char*)(0x04000400+16*(n)))
void ARM7_SetSoundChannelVolume(int channel,int volume,int divisor)
{
 ARM7_RequestedSoundVolume[channel]=volume;
 if(ARM7_SoundVolumeAdjustment>0 && (0xfff5 & (1<<channel))){int pan=PAN(channel);volume=ARM7_AdjustSoundVolume(volume,pan);}
 *(volatile unsigned short*)(0x04000400+16*channel)=volume|(divisor<<8);
}
void ARM7_SetSoundChannelPeriod(int channel,int period)
{
 TIMER(channel*16)=0x10000-period;
}
void ARM7_SetSoundChannelPan(int channel,int pan)
{
 unsigned int offset=16*channel;
 ARM7_RequestedSoundPan[channel]=pan;
 if(ARM7_SoundPanOverride>=0)pan=ARM7_SoundPanOverride;
 *(volatile unsigned char*)(0x04000402+offset)=pan;
 if(ARM7_SoundVolumeAdjustment>0 && (0xfff5 & (1<<channel)))
  *(volatile unsigned char*)(0x04000400+offset)=ARM7_AdjustSoundVolume(ARM7_RequestedSoundVolume[channel],pan);
}
int ARM7_IsSoundChannelActive(int channel)
{
 return (*(volatile unsigned char*)(0x04000403+16*channel)&0x80)!=0;
}
void ARM7_SetSoundPanOverride(int pan)
{
 ARM7_SoundPanOverride=pan;
 if(pan>=0){int channel=0;do{PAN(channel)=pan;channel++;}while(channel<16);}
 else{int channel=0;do{PAN(channel)=ARM7_RequestedSoundPan[channel];channel++;}while(channel<16);}
}
unsigned int ARM7_GetSoundChannelControl(int channel)
{
 return CONTROL(channel*16);
}
