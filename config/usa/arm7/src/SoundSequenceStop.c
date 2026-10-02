/* Sequence stop/pause controls and inclusive-range invalidation. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundSequence ARM7_SoundSequences[16];
extern struct { unsigned int unknown0,activeSequences; } *ARM7_SoundSharedWork;
extern void ARM7_StopSequence(SoundSequence*);
extern SoundTrack *ARM7_GetSequenceTrack(SoundSequence*,int);
extern void ARM7_ReleaseSoundTrackVoices(SoundTrack*,SoundSequence*,int);
extern void ARM7_ClearSoundTrackVoices(SoundTrack*);
void ARM7_StopSoundSequence(int index)
{
 SoundSequence *sequence=&ARM7_SoundSequences[index];
 if(sequence->active){
  ARM7_StopSequence(sequence);
  if(ARM7_SoundSharedWork)ARM7_SoundSharedWork->activeSequences&=~(1<<index);
 }
}
void ARM7_PauseSoundSequence(int index,int paused)
{
 SoundSequence *sequence=&ARM7_SoundSequences[index];
 sequence->paused=paused;
 if(paused){
  int trackIndex=0;
  do{
   SoundTrack *track=ARM7_GetSequenceTrack(sequence,trackIndex);
   if(track){ARM7_ReleaseSoundTrackVoices(track,sequence,127);ARM7_ClearSoundTrackVoices(track);}
   trackIndex++;
  }while(trackIndex<16);
 }
}
