/* Convert envelope fall rates and reset envelope/modulation state for a start. */
#pragma dont_inline on
#include "SoundVoice.h"
unsigned short ARM7_ConvertEnvelopeFallRate(int value)
{
 if(value==127)return 65535;
 if(value==126)return 0x3c00;
 if(value<50)return value*2+1;
 return 0x1e00/(126-value);
}
void ARM7_StartSoundVoice(SoundVoice *voice,int argument)
{
 voice->attenuation=-92544;
 voice->envelopeState=0;
 voice->startArgument=argument;
 voice->modulation.phase=0;
 voice->modulation.counter=0;
 voice->pendingStart=1;
 voice->active=1;
}
