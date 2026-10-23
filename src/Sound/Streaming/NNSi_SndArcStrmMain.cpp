#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
struct Interpolation { int start,end,current,duration; };
struct Sound { char pad[0x3c];int offset;char pad40[8];int count;unsigned char channels[1]; };
struct Job {char pad[0x110];signed int callbackEnabled:1;signed int cleanupEnabled:1;unsigned reserved:30;char rest[0x5c];void(*callback)(Job*);};
// NitroSystem sndarc_stream.c NNSSndStrmPlayer partial data view.
// Full stride 0x174; fader 0xe8, flags 0x110, volumes 0x154..0x15c.
// Stream/file/ADPCM and unrelated callback fields remain opaque here.
struct NNSSndStrmPlayer {
 unsigned char streamAndFile[0xe8];
 Interpolation fader;
 unsigned char adpcmState[0x18];
 signed int activeFlag:1,playFlag:1,startFlag:1,fadeOutFlag:1,dirtyFlag:1,finishFlag:1,monoFlag:1;
 unsigned reserved:25;
 volatile int finishCounter;
 volatile int prepareFlag;
 unsigned char other[0x38];
 int initVolume,extVolume,volume;
 unsigned char tail[0x14];
};
typedef char PlayerStrideIs174[(sizeof(NNSSndStrmPlayer)==0x174)?1:-1];
extern "C" {
 extern NNSSndStrmPlayer NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant6[4];
 extern short NNSiSndArcStrmMain_UnknownRoleInitializedBytes[];
 void ResourceJob_RunCallbacksUnderMutexes(Job*);
 void NNS_SndStrmStart(unsigned char*);
 void NNS_SndStrmSetVolume(Sound*,int);
 void Timer_AdvanceInterpolation(int*);
 int Timer_InterpolateIntegerValue(Interpolation*);
 bool Timer_IsInterpolationComplete(int*);
}
// NitroSDK snd/common/util.h: SND_CalcDecibel returns s16, not int.
static inline short CalcDecibel(int volume) { return NNSiSndArcStrmMain_UnknownRoleInitializedBytes[volume]; }
// Original: arm9/main @ 0x020BED10; symbol: func_020bed10; size: 0x110.
extern "C" void NNSi_SndArcStrmMain() {
 NNSSndStrmPlayer* player;
 int playerNo,volume;
 for(playerNo=0;playerNo<4;++playerNo) {
  player=&NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant6[playerNo];
  if(!player->activeFlag)continue;
  if(player->finishCounter==0){ResourceJob_RunCallbacksUnderMutexes((Job*)player);continue;}
  if(player->startFlag) {if(player->prepareFlag) {
   NNS_SndStrmStart(player->streamAndFile);
   player->playFlag=1;player->startFlag=0;
  }}
  if(!player->playFlag)continue;
  Timer_AdvanceInterpolation((int*)&player->fader);
  volume=CalcDecibel(Timer_InterpolateIntegerValue(&player->fader)>>8)
       +CalcDecibel(player->initVolume)
       +CalcDecibel(player->extVolume);
  if(volume!=player->volume){NNS_SndStrmSetVolume((Sound*)player,volume);player->volume=volume;}
  if(player->fadeOutFlag) {if(Timer_IsInterpolationComplete((int*)&player->fader))ResourceJob_RunCallbacksUnderMutexes((Job*)player);}
 }
}
