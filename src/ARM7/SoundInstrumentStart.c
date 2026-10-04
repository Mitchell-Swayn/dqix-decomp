/* Resolve instrument waveform/type and stage voice key, velocity and ADSR data. */
#pragma dont_inline on
#include "SoundBank.h"
extern Waveform *ARM7_GetSoundWave(SoundWaveArchive*,int);
extern int ARM7_SetSoundVoicePCM(SoundVoice*,const Waveform*,unsigned int,int);
extern int ARM7_SetSoundVoicePSG(SoundVoice*,unsigned int,int);
extern int ARM7_SetSoundVoiceNoise(SoundVoice*,int);
extern void ARM7_SetSoundVoiceAttack(SoundVoice*,int);
extern void ARM7_SetSoundVoiceDecay(SoundVoice*,int);
extern void ARM7_SetSoundVoiceSustain(SoundVoice*,int);
extern void ARM7_SetSoundVoiceRelease(SoundVoice*,int);
int ARM7_StartInstrumentVoice(SoundVoice *voice,int key,int velocity,int argument,SoundBank *bank,const SoundInstrument *instrument)
{
 int release=instrument->parameters.release;
 int result;
 if(release==255){argument=-1;release=0;}
 switch(instrument->type){
 case 1:case 4:{
  Waveform *wave;
  if(instrument->type==1){
   SoundWaveArchive *archive=bank->waveArchives[instrument->parameters.parameter1].archive;
   int index=instrument->parameters.parameter0;
   if(!archive)wave=0;
   else if((unsigned int)index>=archive->count)wave=0;
   else wave=ARM7_GetSoundWave(archive,index);
  }else wave=(Waveform*)((instrument->parameters.parameter1<<16)|instrument->parameters.parameter0);
  if(!wave){result=0;break;}
  result=ARM7_SetSoundVoicePCM(voice,wave,(unsigned int)(wave+1),argument);
  break;
 }
 case 2:result=ARM7_SetSoundVoicePSG(voice,instrument->parameters.parameter0,argument);break;
 case 3:result=ARM7_SetSoundVoiceNoise(voice,argument);break;
 default:result=0;break;
 }
 if(!result)return 0;
 voice->unknown8=key;voice->unknown5=instrument->parameters.baseKey;voice->unknown9=velocity;
 ARM7_SetSoundVoiceAttack(voice,instrument->parameters.attack);
 ARM7_SetSoundVoiceDecay(voice,instrument->parameters.decay);
 ARM7_SetSoundVoiceSustain(voice,instrument->parameters.sustain);
 ARM7_SetSoundVoiceRelease(voice,release);
 voice->unknownA=instrument->parameters.pan-64;
 return 1;
}
