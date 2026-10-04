/* Initialize channel IDs, clear pending-update and active bits, and reset
 * channel reservation masks. Unidentified state bytes retain explicit offset names. */
#pragma dont_inline on
#include "SoundVoice.h"
SoundVoice ARM7_SoundVoices[16];
extern struct { unsigned int mask0,mask1; } ARM7_SoundChannelReservations;
void ARM7_InitializeSoundChannels(void)
{
 int channel=0;
 do{
  ARM7_SoundVoices[channel].channel=channel;
  ARM7_SoundVoices[channel].updates=0;
  ARM7_SoundVoices[channel].active=0;
  channel++;
 }while(channel<16);
 ARM7_SoundChannelReservations.mask0=ARM7_SoundChannelReservations.mask1=0;
}
