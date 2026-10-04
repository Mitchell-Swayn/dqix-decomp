/* Sequence stop/pause controls and inclusive-range invalidation. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundSequence ARM7_SoundSequences[16];
extern void ARM7_StopSequence(SoundSequence*);
extern SoundTrack *ARM7_GetSequenceTrack(SoundSequence*,int);
void ARM7_StopSoundSequencesByCursor(unsigned int start,unsigned int end)
{
 int index=0;
 do{
  SoundSequence *sequence=&ARM7_SoundSequences[index];
  if(sequence->active){
   int trackIndex=0;
   while(trackIndex<16){
    SoundTrack *track=ARM7_GetSequenceTrack(sequence,trackIndex);
    if(track && start<=(unsigned int)track->cursor && (unsigned int)track->cursor<=end){ARM7_StopSequence(sequence);break;}
    trackIndex++;
   }
  }
  index++;
 }while(index<16);
}
void ARM7_StopSoundSequencesByArgument(unsigned int start,unsigned int end)
{
 int index=0;
 do{
  SoundSequence *sequence=&ARM7_SoundSequences[index];
  if(sequence->active && start<=sequence->argument && sequence->argument<=end)ARM7_StopSequence(sequence);
  index++;
 }while(index<16);
}
