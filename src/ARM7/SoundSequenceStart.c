/* Sequence start flags and sized parameter updates preserve original ordering. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundSequence ARM7_SoundSequences[16];
extern void ARM7_PrepareSoundSequence(int,unsigned int,unsigned int,unsigned int);
void ARM7_StartPreparedSoundSequence(int sequence)
{
 ARM7_SoundSequences[sequence].running=1;
}
void ARM7_StartSoundSequence(int sequence,unsigned int data,unsigned int offset,unsigned int argument)
{
 ARM7_PrepareSoundSequence(sequence,data,offset,argument);
 ARM7_SoundSequences[sequence].running=1;
}
