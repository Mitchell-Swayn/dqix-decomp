/* Shared sequence/global variables and sampled channel/capture active masks. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundSharedWork *ARM7_SoundSharedWork;
extern int ARM7_IsSoundChannelActive(int);
extern int ARM7_IsSoundCaptureActive(int);
// Original: arm7/wram @ 0x03802328; symbol: ARM7_SetSoundSequenceVariable.
void ARM7_SetSoundSequenceVariable(int sequence,int index,int value)
{
 ARM7_SoundSharedWork->sequences[sequence].variables[index]=value;
}
// Original: arm7/wram @ 0x03802348; symbol: ARM7_SetSoundGlobalVariable.
void ARM7_SetSoundGlobalVariable(int index,int value)
{
 ((short*)(ARM7_SoundSharedWork+1))[index]=value;
}
// Original: arm7/wram @ 0x03802364; symbol: ARM7_UpdateSoundSharedStatus.
void ARM7_UpdateSoundSharedStatus(void)
{
 unsigned short channels=0,captures=0;
 int index;
 if(ARM7_SoundSharedWork){
  index=0;
  do{if(ARM7_IsSoundChannelActive(index))channels|=1<<index;index++;}while(index<16);
  if(ARM7_IsSoundCaptureActive(0))captures|=1;
  if(ARM7_IsSoundCaptureActive(1))captures|=2;
  ARM7_SoundSharedWork->activeChannels=channels;
  ARM7_SoundSharedWork->activeCaptures=captures;
 }
}
