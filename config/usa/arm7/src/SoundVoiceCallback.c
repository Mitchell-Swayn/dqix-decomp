/* Sound voice callback cleanup and channel reservation/range controls. */
#pragma dont_inline on
#include "SoundVoice.h"
void ARM7_ClearSoundVoiceCallback(SoundVoice *voice)
{
 if(voice){voice->callback=0;voice->userData=0;}
}
