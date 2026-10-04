/* Track data cursors, voice release/cleanup, track lookup, and list callbacks. */
#pragma dont_inline on
#include "SoundSequence.h"
void ARM7_SetSoundTrackData(SoundTrack *track,const unsigned char *data,unsigned int offset)
{
 track->start=data;track->cursor=data+offset;
}
extern SoundTrack ARM7_SoundTracks[32];
extern void ARM7_UpdateSoundTrack(SoundTrack*,SoundSequence*,int);
extern int ARM7_IsSoundVoiceActive(SoundVoice*);
extern void ARM7_SetSoundVoiceRelease(SoundVoice*,int);
extern void ARM7_BeginSoundVoiceRelease(SoundVoice*);
extern void ARM7_ClearSoundVoiceCallback(SoundVoice*);
void ARM7_ReleaseSoundTrackVoices(SoundTrack *track,SoundSequence *sequence,int release)
{
 SoundVoice *voice; unsigned char releaseByte;
 ARM7_UpdateSoundTrack(track,sequence,0);
 voice=track->voices; releaseByte=release;
 while(voice){
  if(ARM7_IsSoundVoiceActive(voice)){
   if(release>=0)ARM7_SetSoundVoiceRelease(voice,releaseByte);
   voice->priority=1;
   ARM7_BeginSoundVoiceRelease(voice);
  }
  voice=voice->next;
 }
}
void ARM7_ClearSoundTrackVoices(SoundTrack *track)
{
 SoundVoice *voice=track->voices;
 while(voice){ARM7_ClearSoundVoiceCallback(voice);voice=voice->next;}
 track->voices=0;
}
SoundTrack *ARM7_GetSequenceTrack(SoundSequence *sequence,int index)
{
 int id;
 if(index>15)return 0;
 id=sequence->trackIds[index];
 if(id==255)return 0;
 return &ARM7_SoundTracks[id];
}
void ARM7_StopSequenceTrack(SoundSequence *sequence,int index)
{
 SoundTrack *track=ARM7_GetSequenceTrack(sequence,index);
 if(track){
  ARM7_ReleaseSoundTrackVoices(track,sequence,-1);
  ARM7_ClearSoundTrackVoices(track);
  ARM7_SoundTracks[sequence->trackIds[index]].active=0;
  sequence->trackIds[index]=255;
 }
}
void ARM7_StopSequence(SoundSequence *sequence)
{
 int index=0;
 do{ARM7_StopSequenceTrack(sequence,index);index++;}while(index<16);
 sequence->active=0;
}

extern void ARM7_ClearSoundVoiceCallback(SoundVoice*);
void ARM7_SoundTrackVoiceCallback(SoundVoice *voice,int event,void *userData)
{
 SoundTrack *track=userData;
 SoundVoice *previous;
 if(event==1){voice->priority=0;ARM7_ClearSoundVoiceCallback(voice);}
 previous=track->voices;
 if(previous==voice)track->voices=voice->next;
 else {
  while(previous->next){
   if(previous->next==voice){previous->next=voice->next;break;}
   previous=previous->next;
  }
 }
}
