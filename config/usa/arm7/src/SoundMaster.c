/* Sound master enable, channel reset, power sequencing, volume and routing.
 * Power-management hooks remain opaque dependencies. BIOS ramps are called
 * through their Thumb entries; this unit contains only ordinary C. */
#pragma dont_inline on
#define SOUND_CONTROL_HIGH (*(volatile unsigned char*)0x04000501)
#define SOUND_MASTER_VOLUME (*(volatile unsigned char*)0x04000500)
#define SOUND_POWER (*(volatile unsigned short*)0x04000304)
extern void ARM7_StopSoundChannel(int,unsigned int);
extern void ARM7_WaitCycles(int);
extern void ARM7_SoundPowerOffHook(int);
extern void ARM7_SoundPowerOnHook(int);
extern void ARM7_BiosSoundBiasDown(int);
extern void ARM7_BiosSoundBiasUp(int);
void ARM7_RampSoundBiasDown(int);
void ARM7_RampSoundBiasUp(int);
void ARM7_EnableSoundMaster(void)
{
 SOUND_CONTROL_HIGH|=0x80;
}
void ARM7_ResetSoundChannels(void)
{
 int channel;
 SOUND_CONTROL_HIGH&=~0x80;
 channel=0;
 do { ARM7_StopSoundChannel(channel,1); channel++; } while(channel<16);
 *(volatile unsigned char*)0x04000508=0;
 *(volatile unsigned char*)0x04000509=0;
}
void ARM7_PowerOffSound(void)
{
 SOUND_CONTROL_HIGH&=~0x80;
 ARM7_RampSoundBiasDown(0x80);
 ARM7_WaitCycles(0x40000);
 ARM7_SoundPowerOffHook(1);
 SOUND_POWER&=~1;
}
void ARM7_RampSoundBiasDown(int delay)
{
 ARM7_BiosSoundBiasDown(delay);
}
void ARM7_PowerOnSound(void)
{
 SOUND_POWER|=1;
 ARM7_SoundPowerOnHook(1);
 ARM7_RampSoundBiasUp(0x100);
 ARM7_WaitCycles(0x7ab80);
 SOUND_CONTROL_HIGH|=0x80;
}
void ARM7_RampSoundBiasUp(int delay)
{
 ARM7_BiosSoundBiasUp(delay);
}
void ARM7_SetSoundMasterVolume(unsigned int volume)
{
 SOUND_MASTER_VOLUME=volume;
}
void ARM7_SetSoundOutputRouting(unsigned int left,unsigned int right,unsigned int channel1,unsigned int channel3)
{
 unsigned int enabled=(SOUND_CONTROL_HIGH&0x80)!=0;
 SOUND_CONTROL_HIGH=(enabled<<7)|(channel3<<5)|(channel1<<4)|(right<<2)|left;
}
