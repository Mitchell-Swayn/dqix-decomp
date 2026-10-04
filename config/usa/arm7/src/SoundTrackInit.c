/* Recovered sequence/track control; unknown policy fields keep offset names. */
#pragma dont_inline on
#include "SoundSequence.h"
extern void ARM7_InitializeSoundModulation(SoundModulationParameters*);
void ARM7_InitializeSoundTrack(SoundTrack *track)
{
 track->start=0;track->cursor=0;
 track->unknownFlag1=1;track->muted=0;track->unknownFlag3=0;track->unknownFlag4=0;track->unknownFlag5=0;track->unknownFlag6=1;track->parameter1EChanged=0;
 track->unknown3B=0;track->unknown2=0;track->unknown12=64;track->unknown4=127;track->unknown5=127;
 track->unknownA=0;track->unknown8=0;track->unknown9=0;track->unknown6=0;track->unknownC=0;
 track->unknownE=255;track->unknownF=255;track->unknown10=255;track->unknown11=255;track->unknown1=127;
 track->unknown7=2;track->unknown14=60;track->unknown15=0;track->unknown16=0;track->unknown13=0;track->parameter1E=65535;
 ARM7_InitializeSoundModulation(&track->modulation);
 track->unknown20=0;track->voices=0;
}
