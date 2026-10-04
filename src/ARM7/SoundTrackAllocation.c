/* Track allocation, mute modes and updates selected by track masks. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundTrack ARM7_SoundTracks[32];
extern void ARM7_ReleaseSoundTrackVoices(SoundTrack*,SoundSequence*,int);
extern void ARM7_ClearSoundTrackVoices(SoundTrack*);
int ARM7_AllocateSoundTrack(void)
{
 int index;
 for(index=0;index<32;index++){
  SoundTrack *track=&ARM7_SoundTracks[index]; if(!track->active){track->active=1;return index;}
 }
 return -1;
}
void ARM7_SetSoundTrackMute(SoundTrack *track,SoundSequence *sequence,int mode)
{
 switch(mode){
 case 0:track->muted=0;break;
 case 1:track->muted=1;break;
 case 2:track->muted=1;ARM7_ReleaseSoundTrackVoices(track,sequence,-1);break;
 case 3:track->muted=1;ARM7_ReleaseSoundTrackVoices(track,sequence,127);ARM7_ClearSoundTrackVoices(track);break;
 }
}
