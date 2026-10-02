/* Recovered sequence/track control; unknown policy fields keep offset names. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundSharedWork *ARM7_SoundSharedWork;
extern SoundSequence ARM7_SoundSequences[16];
extern SoundTrack *ARM7_GetSequenceTrack(SoundSequence*,int);
extern void ARM7_ReleaseSoundTrackVoices(SoundTrack*,SoundSequence*,int);
extern void ARM7_ClearSoundTrackVoices(SoundTrack*);
extern void ARM7_StopSoundWorkerAlarm(void);
extern void ARM7_StartSoundWorkerAlarm(void);
extern int ARM7_ProcessSequenceTick(SoundSequence*,int);
extern void ARM7_StopSequence(SoundSequence*);
void ARM7_AdvanceSoundSequence(int index,unsigned int ticks)
{
 SoundSequence *sequence=&ARM7_SoundSequences[index];
 SoundTrack *track;
 int trackIndex=0;
 unsigned int count;
 do{
  track=ARM7_GetSequenceTrack(sequence,trackIndex);
  if(track){ARM7_ReleaseSoundTrackVoices(track,sequence,127);ARM7_ClearSoundTrackVoices(track);}
  trackIndex++;
 }while(trackIndex<16);
 ARM7_StopSoundWorkerAlarm();
 for(count=0;count<ticks;count++){
  if(ARM7_ProcessSequenceTick(sequence,0)){ARM7_StopSequence(sequence);break;}
 }
 ARM7_StartSoundWorkerAlarm();
 if(ARM7_SoundSharedWork)ARM7_SoundSharedWork->sequences[sequence->index].ticks+=count;
}
