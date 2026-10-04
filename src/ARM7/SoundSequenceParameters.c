/* Sequence start flags and sized parameter updates preserve original ordering. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundSequence ARM7_SoundSequences[16];
extern SoundTrack *ARM7_GetSequenceTrack(SoundSequence*,int);
void ARM7_WriteSoundSequenceParameter(int sequence,int offset,unsigned int value,int size)
{
 unsigned char *record=(unsigned char*)&ARM7_SoundSequences[sequence];
 switch(size){
 case 1:*(unsigned char*)(record+offset)=value;break;
 case 2:*(unsigned short*)(record+offset)=value;break;
 case 4:*(unsigned int*)(record+offset)=value;break;
 }
}
void ARM7_WriteSoundTrackParameter(int sequence,unsigned int mask,int offset,unsigned int value,int size)
{
 SoundSequence *player=&ARM7_SoundSequences[sequence]; int track=0;
 while(track<16 && mask){
  if(mask&1){
   unsigned char *record=(unsigned char*)ARM7_GetSequenceTrack(player,track);
   if(record){
    switch(size){
    case 1:*(unsigned char*)(record+offset)=value;break;
    case 2:*(unsigned short*)(record+offset)=value;break;
    case 4:*(unsigned int*)(record+offset)=value;break;
    }
   }
  }
  track++;mask>>=1;
 }
}
