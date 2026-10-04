/* Clear sequence/track active bits and assign sequence indices. Other fields remain unknown. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundSequence ARM7_SoundSequences[16];
extern SoundTrack ARM7_SoundTracks[32];
void ARM7_InitializeSoundSequences(void)
{
 int index=0; int track;
 do{SoundSequence *sequence=&ARM7_SoundSequences[index];sequence->active=0;sequence->index=index;index++;}while(index<16);
 track=0; do{ARM7_SoundTracks[track].active=0;track++;}while(track<32);
}
