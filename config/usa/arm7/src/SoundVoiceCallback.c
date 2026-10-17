/* Sound voice callback cleanup and channel reservation/range controls. */
#pragma dont_inline on
#include "SoundVoice.h"
// Original: arm7/wram @ 0x038001D4; symbol: ARM7_ClearSoundVoiceCallback.
void ARM7_ClearSoundVoiceCallback(SoundVoice *voice)
{
 if(voice){voice->callback=0;voice->userData=0;}
}
