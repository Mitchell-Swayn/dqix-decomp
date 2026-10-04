/* Recovered sequence/track control; unknown policy fields keep offset names. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundSharedWork *ARM7_SoundSharedWork;
short *ARM7_GetSoundSequenceVariable(SoundSequence *sequence,int index)
{
 if(!ARM7_SoundSharedWork)return 0;
 if(index<16)return &ARM7_SoundSharedWork->sequences[sequence->index].variables[index]; else return (short*)(ARM7_SoundSharedWork+1)+(index-16);
}
