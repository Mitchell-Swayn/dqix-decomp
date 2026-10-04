/* Track allocation, mute modes and updates selected by track masks. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundSequence ARM7_SoundSequences[16];
extern SoundTrack *ARM7_GetSequenceTrack(SoundSequence*,int);
extern void ARM7_SetSoundTrackMute(SoundTrack*,SoundSequence*,int);
void ARM7_SetSequenceTrackMute(int index,unsigned int mask,int mode)
{
 SoundSequence *sequence=&ARM7_SoundSequences[index];
 int trackIndex=0;
 while(trackIndex<16 && mask){
  if(mask&1){
   SoundTrack *track=ARM7_GetSequenceTrack(sequence,trackIndex);
   if(track)ARM7_SetSoundTrackMute(track,sequence,mode);
  }
  trackIndex++;mask>>=1;
 }
}
void ARM7_SetSequenceTrackParameter1E(int index,unsigned int mask,unsigned int parameter)
{
 SoundSequence *sequence=&ARM7_SoundSequences[index];
 int trackIndex=0;
 while(trackIndex<16 && mask){
  if(mask&1){
   SoundTrack *track=ARM7_GetSequenceTrack(sequence,trackIndex);
   if(track){track->parameter1E=parameter;track->parameter1EChanged=1;}
  }
  trackIndex++;mask>>=1;
 }
}
