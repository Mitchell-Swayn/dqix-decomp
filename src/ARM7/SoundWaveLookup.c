/* Resolve zero, archive-relative and absolute waveform entries. */
#pragma dont_inline on
#include "SoundBank.h"
extern void ARM7_BeginSoundBankAccess(void);
extern void ARM7_EndSoundBankAccess(void);
Waveform *ARM7_GetSoundWave(SoundWaveArchive *archive,int index)
{
 unsigned char *address;
 ARM7_BeginSoundBankAccess();
 address=(unsigned char*)((unsigned int*)(archive+1))[index];
 if(address){if((unsigned int)address<0x02000000)address=(unsigned char*)archive+(unsigned int)address;}
 else address=0;
 ARM7_EndSoundBankAccess();
 return (Waveform*)address;
}
